#include <bits/stdc++.h>
using namespace std;
int A[1000006];
long double ans[1000006];
int l[1000006], r[1000006];
int hcnt[1000006];
long long B[1000006];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  stack<pair<int, int>> S;
  S.emplace(0, 0);
  for (int i = 1; i <= n; ++i) {
    while (S.top().first >= A[i]) S.pop();
    l[i] = i - S.top().second;
    S.emplace(A[i], i);
  }
  decltype(S)().swap(S);
  S.emplace(0, n + 1);
  for (int i = n; i >= 1; --i) {
    while (S.top().first > A[i]) S.pop();
    r[i] = S.top().second - i;
    S.emplace(A[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    B[1] += A[i], B[l[i] + 1] -= A[i];
    B[r[i] + 1] -= A[i], B[l[i] + r[i] + 1] += A[i];
  }
  for (int i = 1; i <= n; ++i) B[i] += B[i - 1];
  for (int i = 1; i <= n; ++i) B[i] += B[i - 1];
  for (int i = 1; i <= n; ++i) ans[i] = (long double)B[i] / (n - i + 1);
  cin >> m;
  cout << fixed;
  cout.precision(16);
  while (m--) {
    int k;
    cin >> k, printf("%.15f\n", double(ans[k]));
  }
  return 0;
}
