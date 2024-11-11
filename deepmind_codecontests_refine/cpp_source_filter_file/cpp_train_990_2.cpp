#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> p;
int A[N];
int n;
long long a, b;
int mark[N];
long long prefix[N], suffix[N];
long long ans = LLONG_MAX;
void compute(int x) {
  memset(mark, 0, sizeof mark);
  memset(prefix, -1, sizeof prefix);
  memset(suffix, -1, sizeof suffix);
  for (int i = 1; i <= n; i++) {
    if ((A[i] % x) == 0)
      continue;
    else if ((A[i] % x) == 1 or (A[i] % x) == n - 1)
      mark[i] = 1;
    else
      mark[i] = 2;
  }
  prefix[0] = suffix[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    if (mark[i] == 2)
      break;
    else
      prefix[i] = prefix[i - 1] + (mark[i] == 1);
  }
  for (int i = n; i >= 1; i--) {
    if (mark[i] == 2)
      break;
    else
      suffix[i] = suffix[i + 1] + (mark[i] == 1);
  }
  for (int i = n; i >= 1; i--) {
    if (suffix[i] == -1) break;
    ans = min(ans, suffix[i] * b + (i - 1) * 1LL * a);
  }
  suffix[n + 1] = (n + 1) * 1LL * a;
  for (int i = n; i >= 1; i--) {
    if (suffix[i] == -1)
      suffix[i] = suffix[i + 1];
    else
      suffix[i] = min(suffix[i + 1], suffix[i] * b + i * 1LL * a);
  }
  for (int i = 1; i <= n; i++) {
    if (prefix[i] == -1) break;
    ans = min(ans, prefix[i] * b + suffix[i + 1] - a * 1LL * (i + 1));
  }
}
void solve(int x) {
  if (x == 1) return;
  p.clear();
  for (long long i = 2; i * i <= x;) {
    if ((x % i) == 0) {
      p.insert(i);
      x /= i;
    } else
      i++;
  }
  if (x != 1) p.insert(x);
  for (auto it : p) compute(it);
}
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> A[i];
  solve(A[1]);
  solve(A[1] + 1);
  solve(A[1] - 1);
  solve(A[n]);
  solve(A[n] + 1);
  solve(A[n] - 1);
  cout << ans;
}
