#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const vector<int> mods = {998244353, 1000000007, 1000000009};
const long long inf = 3e18;
const double pi = acos(-1.0);
const double eps = 0.0000001;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class... K>
using umap = unordered_map<K...>;
template <class... K>
using uset = unordered_set<K...>;
long long n, res, cur[3];
string s;
vector<long long> cw[2], fw[2][1000100];
void ps(long long ci, long long i) {
  if (s[i] == '?')
    cw[ci][2]++;
  else {
    long long ty = s[i] - '0';
    if (cw[ci][2] || ty != cw[ci][0])
      cw[ci] = {ty, 1 + cw[ci][2], 0};
    else
      cw[ci][1]++;
  }
  fw[ci][i] = cw[ci];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin >> n >> s;
  char ls = '2';
  long long prv = -1;
  for (long long i = (0); i < (n); ++i) {
    if (s[i] == '?') continue;
    if (s[i] == ls || ls == '2') {
      for (long long j = i - 1; j > prv; j--) s[j] = s[i];
    }
    ls = s[i];
    prv = i;
  }
  for (long long j = n - 1; j > prv; j--) s[j] = (ls == '2' ? '0' : ls);
  cw[0] = cw[1] = {0, 0, 0};
  for (long long i = (0); i < (n); ++i) {
    ps(0, n - 1 - i);
    ps(1, i);
  }
  for (long long block = (1); block < (n + 1); ++block) {
    res = 0;
    cur[1] = cur[2] = 0;
    for (long long i = 0; i < n; i += block) {
      vector<long long>& cf = fw[0][i];
      long long tk = 0;
      if (cur[0] == cf[0] && cur[1] + cf[1] >= block) {
        tk = block - cur[1];
        res++;
      } else if (cur[1] + cur[2] + cf[2] >= block) {
        tk = block - cur[2] - cur[1];
        res++;
      } else if (cur[2] + cf[2] + cf[1] >= block) {
        tk = block - cur[2];
        res++;
      }
      if (i + block - 1 < n) {
        vector<long long>& cb = fw[1][i + block - 1];
        cur[0] = cb[0];
        cur[2] = min(block - tk, cb[2]);
        cur[1] = min(block - tk - cur[2], cb[1]);
        if (cur[1] + cur[2] >= block) {
          res++;
          cur[1] = cur[2] = 0;
        }
      }
    }
    cout << res << " \n"[block == n];
  }
  return 0;
}
