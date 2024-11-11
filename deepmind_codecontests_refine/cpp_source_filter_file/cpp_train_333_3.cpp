#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {0, 1, 0, -1};
const long long dy[] = {1, 0, -1, 0};
const long long inf = 0x3f3f3f3f3f3f3f;
const long long N = 2e5 + 11;
long long n, k, dp[N][2];
long long anss = inf;
map<long long, long long> di, insert;
void prec(map<long long, long long> s, long long turn) {
  long long nr = 0;
  long long mn = -1;
  long long ans = 0;
  long long i = (turn == 1 ? n : 1);
  for (auto it : s) {
    long long cur = it.first;
    long long frec = it.second;
    if (mn != -1) {
      ans += nr * (cur - mn);
    }
    nr += frec;
    mn = cur;
    dp[i][turn] = ans;
    if (turn)
      i--;
    else
      i++;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1, x; i <= n; i++) {
    cin >> x;
    di[x]++;
    insert[-x]++;
    if (di[x] >= k) {
      anss = 0;
    }
  }
  long long len = n;
  n = (long long)((insert).size());
  vector<pair<long long, long long> > v;
  v.push_back(make_pair(0, 0));
  for (auto it : insert) {
    v.push_back(make_pair(it.first, it.second));
  }
  prec(di, 0);
  prec(insert, 1);
  for (long long i = 1; i <= n; i++) {
    anss = min(anss, dp[i][0] + dp[i][1] - (len - k));
  }
  long long nr = 0;
  for (long long i = 1; i <= n; i++) {
    if (nr + v[i].second >= k) {
      anss = min(anss, dp[i][0] - (nr + v[i].second - k));
      break;
    }
    nr += v[i].second;
  }
  nr = 0;
  for (long long i = n; i > 0; i--) {
    if (nr + v[i].second >= k) {
      anss = min(anss, dp[i][1] - (nr + v[i].second - k));
      break;
    }
    nr += v[i].second;
  }
  cout << max(0ll, anss) << '\n';
  return 0;
}
