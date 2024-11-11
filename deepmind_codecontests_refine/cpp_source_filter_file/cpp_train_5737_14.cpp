#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(const T& t) {
  ostringstream os;
  os << t;
  return os.str();
}
int N;
const int MX = 300000;
vector<pair<int, int> > dat;
pair<int, int> pref[MX + 10];
pair<int, int> suff[MX + 10];
pair<int, int> getOverlap(pair<int, int> a, pair<int, int> b) {
  if (a > b) swap(a, b);
  if (a.second < b.first) return pair<int, int>(-1, -1);
  return pair<int, int>(max(a.first, b.first), min(a.second, b.second));
}
int main() {
  cin >> N;
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    dat.push_back(p);
  }
  int best = 0;
  sort((dat).begin(), (dat).end());
  if (N == 1) {
    cout << dat[0].second - dat[0].first;
    return 0;
  }
  if (N == 2) {
    best = dat[0].second - dat[0].first;
    best = max(best, dat[1].second - dat[1].first);
    cout << best;
    return 0;
  }
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    if (i == 0)
      pref[i] = getOverlap(dat[0], dat[0]);
    else
      pref[i] = getOverlap(dat[i], dat[i - 1]);
  }
  for (int i = (int)(N - 1); i >= (int)(0); --i) {
    if (i == N - 1)
      suff[i] = getOverlap(dat[N - 1], dat[N - 1]);
    else
      suff[i] = getOverlap(dat[i], dat[i + 1]);
  }
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    int dist = 0;
    if (i == 0) {
      dist = suff[1].second - suff[1].first;
    } else if (i == N - 1) {
      dist = pref[N - 2].second - pref[N - 2].first;
    } else {
      int prev = i - 1;
      int next = i + 1;
      if (pref[prev] == pair<int, int>(-1, -1) ||
          suff[next] == pair<int, int>(-1, -1))
        continue;
      auto overlap = getOverlap(pref[prev], suff[next]);
      if (overlap == pair<int, int>(-1, -1)) continue;
      dist = overlap.second - overlap.first;
    }
    best = max(best, dist);
  }
  cout << best;
  return 0;
}
