#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> sub(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return pair<long long, long long>(a.first - b.first, a.second - b.second);
}
pair<long long, long long> add(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return pair<long long, long long>(a.first + b.first, a.second + b.second);
}
long long dp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.first + a.second * b.second;
}
long long cp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second - a.second * b.first;
}
long double polar(pair<long long, long long> a, pair<long long, long long> b) {
  return atan2(cp(a, b), dp(a, b));
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, long long> > ps(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
    pos[i] = i;
  }
  pair<long long, long long> start = ps[0];
  int mni = 0;
  for (int i = 1; i < n; i++) {
    if (ps[i].first < start.first ||
        (ps[i].first == start.first && ps[i].second < start.second)) {
      start = ps[i];
      mni = i;
    }
  }
  vector<int> ans;
  ans.push_back(mni);
  swap(ps[mni], ps.back());
  ps.pop_back();
  swap(pos[mni], pos.back());
  pos.pop_back();
  pair<long long, long long> prv =
      pair<long long, long long>(start.first - 1, start.second);
  string s;
  cin >> s;
  for (int it = 0; it < n - 2; it++) {
    int mni = 0;
    pair<long long, long long> nw = ps[0];
    long double mn = polar(sub(start, prv), sub(nw, start));
    for (int i = 1; i < ps.size(); i++) {
      long double alpha = polar(sub(start, prv), sub(ps[i], start));
      if (s[it] == 'R') {
        if (alpha > mn) {
          mn = alpha;
          mni = i;
          nw = ps[i];
        }
      } else {
        if (alpha < mn) {
          mn = alpha;
          mni = i;
          nw = ps[i];
        }
      }
    }
    prv = start;
    start = nw;
    ans.push_back(pos[mni]);
    swap(ps[mni], ps.back());
    ps.pop_back();
    swap(pos[mni], pos.back());
    pos.pop_back();
  }
  ans.push_back(pos.back());
  for (int t : ans) {
    cout << t + 1 << " ";
  }
  return 0;
}
