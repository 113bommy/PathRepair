#include <bits/stdc++.h>
using namespace std;
const string B = "BERLAND";
const int M = 100;
struct S {
  string name;
  int score, get, miss, ct;
  S() : score(0), get(0), miss(0), ct(0) {}
  bool operator<(const S &s) const {
    if (score != s.score)
      return score > s.score;
    else if (get - miss != s.get - s.miss)
      return get - miss > s.get - s.miss;
    else if (get != s.get)
      return get > s.get;
    else
      return name < s.name;
    return false;
  };
};
map<string, S> mp;
bool feasible(const map<string, S> &mp) {
  vector<S> v;
  for (typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); ++it)
    v.push_back(it->second);
  sort((v).begin(), (v).end());
  if (v[0].name == B or v[1].name == B) return true;
  return false;
}
struct T {
  bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
    if (l.first - l.second != r.first - r.second)
      return l.first - l.second < r.first - r.second;
    else if (l.second != r.second)
      return l.second < r.second;
    return false;
  }
};
vector<pair<int, int> > ans;
int main() {
  for (int i = 0; i < (int)(5); ++i) {
    string t1, t2;
    int g1, g2;
    cin >> t1 >> t2;
    scanf("%d:%d", &g1, &g2);
    mp[t1].ct++;
    mp[t2].ct++;
    mp[t1].get += g1;
    mp[t1].miss += g2;
    mp[t2].get += g2;
    mp[t2].miss += g1;
    if (g1 > g2) {
      mp[t1].score += 3;
    } else if (g1 < g2) {
      mp[t2].score += 3;
    } else {
      mp[t1].score += 1;
      mp[t2].score += 1;
    }
  }
  for (typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); ++it)
    it->second.name = it->first;
  assert(mp.size() == 4);
  int j = 0;
  string s;
  for (typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); ++it) {
    if (it->second.ct == 2 and it->first != B) s = it->first;
  }
  for (int X = 0; X < M; X++) {
    for (int Y = 0; Y < M; Y++) {
      if (X <= Y) continue;
      map<string, S> mp2 = mp;
      mp2[B].get += X;
      mp2[B].miss += Y;
      mp2[s].get += Y;
      mp2[s].miss += X;
      mp2[B].score += 3;
      if (feasible(mp2)) {
        ans.push_back(make_pair(X, Y));
      }
    }
  }
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  sort((ans).begin(), (ans).end(), T());
  cout << ans.front().first << ":" << ans.front().second << endl;
  return 0;
}
