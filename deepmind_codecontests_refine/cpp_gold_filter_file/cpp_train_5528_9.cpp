#include <bits/stdc++.h>
using namespace std;
long long n, m, q, k;
string s;
int MOD = 1e9 + 7;
const int INF = 1e9;
const long long INF64 = 2e18;
const double PI = 3.141592653589793238463;
long long ar[100004], ar1[100004], vis[100004], pre[100004], dp[3004][3004];
vector<long long> gr[100004], path;
set<long long> myset;
pair<long long, long long> seg[100004], seg1[100004];
map<long long, long long> mymap;
string st1[100004], st2[100004];
vector<long long> arr[100004];
int comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> s;
  long long pre = 1, suf = 1;
  for (int i = 1; i < int(s.size()); i++) {
    if ((s[i] == 'w' && s[i - 1] == 'b') || (s[i] == 'b' && s[i - 1] == 'w'))
      pre++;
    else
      break;
  }
  for (int i = s.size() - 2; i >= 0; i--) {
    if ((s[i] == 'w' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'w'))
      suf++;
    else
      break;
  }
  long long siz = 0, prev = -1, maxval = INT_MIN;
  for (int i = pre; i < s.size(); i++) {
    if (!siz)
      prev = s[i], siz++;
    else {
      if (s[i] != prev)
        prev = s[i], siz++;
      else
        i--, maxval = max(maxval, siz), siz = 0;
    }
  }
  if (pre + suf > s.size()) return cout << s.size(), 0;
  if (s[0] != s[s.size() - 1]) return cout << max(pre + suf, maxval), 0;
  return cout << max(pre, max(suf, maxval)), 0;
}
