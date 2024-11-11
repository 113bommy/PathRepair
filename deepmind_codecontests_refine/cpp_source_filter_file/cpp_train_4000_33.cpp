#include <bits/stdc++.h>
using namespace std;
long long w[100005];
int n, m;
bool cmp(long long A, long long B) { return A > B; }
bool can(int K) {
  if (K & 1) return K * (K - 1) / 2 + 1 <= n;
  return K * K / 2 <= n;
}
int binary(int r) {
  while (r) {
    if (can(r)) return r;
    r--;
  }
}
int main() {
  cin >> n >> m;
  int t;
  for (int i = 0; i < m; i++) scanf("%d %I64d", &t, &w[i]);
  sort(w, w + m, cmp);
  for (int i = 1; i < m; i++) w[i] += w[i - 1];
  cout << w[binary(m) - 1] << endl;
  return 0;
}
