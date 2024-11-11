#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double EPS = 1e-9, INF = 1e12;
map<int, int> dp;
int rec(int n) {
  int m = sqrt(n);
  n = min(n, m * m + 2);
  if (dp.count(n)) return dp[n];
  int b = sqrt(n), a = (int)ceil(sqrt(sqrt(n * 1.0)) - EPS);
  set<int> s;
  for (int i = a; i <= b; i++) {
    if (i < n) s.insert(rec(i));
  }
  for (int i = 0;; i++) {
    if (!s.count(i)) return dp[n] = i;
  }
}
int cnt[100];
long long in[100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (int)n; i++) cin >> in[i];
  sort(in, in + n);
  int ans = 0;
  int l = 0, r = 0;
  for (int i = 0; i < (int)n; i++) {
    int a = (int)ceil(sqrt(sqrt(in[i] * 1.0)) - EPS);
    int b = sqrt(in[i]);
    if (b >= in[i]) b--;
    a = min(a, b + 1);
    while (r <= b) cnt[rec(r++)]++;
    while (l < a) cnt[rec(l++)]--;
    for (int j = 0;; j++)
      if (!cnt[j]) {
        ans ^= j;
        break;
      }
  }
  cout << (ans ? "Furlo" : "Rublo") << endl;
  return 0;
}
