#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int sz(const T& x) {
  return (int)x.size();
}
map<int, string> id2name;
struct racer {
  int score;
  int id;
  inline bool operator<(const racer& x) const {
    if (score != x.score) return score > x.score;
    return id2name[id] < id2name[x.id];
  }
  inline bool operator>(const racer& x) const {
    if (score != x.score) return score < x.score;
    return id2name[id] > id2name[x.id];
  }
};
int N, M;
int a[100015];
int b[100015];
int v;
vector<racer> racers;
bool atmost(int am, int av) {
  int first = 0, last = N - 2;
  racer va;
  va.score = av;
  va.id = v;
  for (int i = 0; i < sz(racers) && am >= 0; ++i) {
    if (racers[i].id == v) continue;
    racer r;
    r.score = racers[i].score;
    r.id = racers[i].id;
    if (am > 0)
      r.score = racers[i].score + b[last--];
    else
      r.score = racers[i].score + b[first++];
    if (r < va) --am;
  }
  return am >= 0;
}
int solve_best() {
  int av = a[v] + b[N - 1];
  if (atmost(0, av)) return 1;
  int lo = 0, hi = N - 1;
  while (hi - lo > 1) {
    int mi = (lo + hi) >> 1;
    if (atmost(mi, av))
      hi = mi;
    else
      lo = mi;
  }
  return hi + 1;
}
bool atleast(int am, int av) {
  int first = 1, last = N - 1;
  racer va;
  va.score = av;
  va.id = v;
  am = N - 1 - am;
  for (int i = sz(racers) - 1; i >= 0; --i) {
    if (racers[i].id == v) continue;
    racer r;
    r.score = racers[i].score;
    r.id = racers[i].id;
    if (am > 0)
      r.score = racers[i].score + b[first++];
    else
      r.score = racers[i].score + b[last--];
    if (r > va) --am;
  }
  return am >= 0;
}
int solve_worst() {
  int av = a[v] + b[0];
  if (atleast(N - 1, av)) return N;
  int lo = 0, hi = N - 1;
  while (hi - lo > 1) {
    int mi = (lo + hi) >> 1;
    if (atleast(mi, av))
      hi = mi;
    else
      lo = mi;
  }
  return lo + 1;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> N;
  map<string, int> names;
  int count = 0;
  racers.clear();
  for (int i = 0; i < N; ++i) {
    string s;
    int sc;
    cin >> s >> sc;
    names[s] = count;
    id2name[count] = s;
    racer r;
    r.score = sc;
    r.id = count;
    racers.push_back(r);
    a[count] = sc;
    ++count;
  }
  sort(racers.begin(), racers.end());
  memset(b, 0, sizeof b);
  cin >> M;
  for (int i = 0; i < M; ++i) cin >> b[i];
  sort(b, b + N);
  string vasya;
  cin >> vasya;
  v = names[vasya];
  int best = solve_best();
  int worst = solve_worst();
  cout << best << ' ' << worst << endl;
  return 0;
}
