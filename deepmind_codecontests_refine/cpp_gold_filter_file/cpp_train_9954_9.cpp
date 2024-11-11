#include <bits/stdc++.h>
using namespace std;
int P;
int ksm(int a, int b, int P) {
  int c = 1, d = a;
  while (b) {
    if (b & 1) c = (long long)c * d % P;
    d = (long long)d * d % P;
    b >>= 1;
  }
  return c;
}
vector<int> ans;
int main() {
  int n, m, a, q, now, i, C;
  cin >> n >> m >> a >> q;
  now = a % q;
  for (i = 1;; i++) {
    if (now == 1) break;
    now = (long long)now * a % q;
  }
  P = i;
  now = 1;
  C = 1;
  for (i = 1; i <= n; i++) {
    ans.push_back(ksm(a, now, q));
    if (i <= m)
      C = (long long)C * (m - i + 1) % P * ksm(i, P - 2, P) % P;
    else
      C = 0;
    now = (now + C) % P;
  }
  reverse(ans.begin(), ans.end());
  for (auto it : ans) printf("%d ", it);
  cout << endl;
  return 0;
}
