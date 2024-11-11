#include <bits/stdc++.h>
using namespace std;
const int N = 400010, P = 131;
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
priority_queue<int, vector<int>, greater<int>> heap;
int n, m, t;
int g[510][510];
int p[N], edge[N], a[N], b[N], ans[N];
int st[N], primes[N], cnt, cnt1;
bool stt[N];
map<int, int> mp[110];
vector<int> all;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long qmi(long long a, long long k, long long p) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % p;
    k >>= 1;
    a = a * a % p;
  }
  return res;
}
bool cmp(int a, int b) { return a > b; }
int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    cnt++;
    int f = 0;
    for (int j = 0; j < t; j++) {
      if (!f) {
        cnt1++;
        f = 1;
      }
      int x;
      cin >> x;
      mp[cnt][x] = 1;
    }
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i + 1 <= n; i++)
    if (mp[i].size())
      for (int j = i + 1; j <= n; j++)
        if (mp[j].size())
          for (auto t : mp[i])
            if (mp[j].count(t.first)) {
              p[find(i)] = find(j);
              break;
            }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!stt[find(i)] && mp[i].size()) {
      stt[find(i)] = true;
      res++;
    }
  }
  if (cnt1)
    cout << res + n - cnt1 - 1 << endl;
  else
    cout << n << endl;
  return 0;
}
