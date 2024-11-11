#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e5 + 228;
const char nxtl = '\n';
const int mod = (int)1e9 + 7;
const double eps = (double)1e-9;
template <typename T>
inline bool updmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool updmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int n, a, b, k;
char s[MAXN];
vector<int> res;
vector<pair<int, int> > v;
int nxt[MAXN];
int all;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b >> k;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  s[n + 1] = '1';
  s[0] = '1';
  int last = n + 1;
  for (int i = n; i >= 0; --i) {
    if (s[i] == '1') {
      nxt[i] = last, last = i;
      int cnt = (nxt[i] - last - 1) / b;
      all += cnt;
      if (cnt > 0) v.push_back(make_pair(cnt, i + b));
    }
  }
  sort(v.begin(), v.end());
  int ptr = 0;
  while (all >= a) {
    while (all >= a && v[ptr].first > 0) {
      v[ptr].first--;
      res.push_back(v[ptr].second);
      v[ptr].second += b;
      all--;
    }
    ptr++;
  }
  cout << ((int)(res.size())) << nxtl;
  for (auto &to : res) cout << to << ' ';
  return 0;
}
