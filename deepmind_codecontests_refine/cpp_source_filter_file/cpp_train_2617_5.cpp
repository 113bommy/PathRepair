#include <bits/stdc++.h>
using namespace std;
long long int A, B;
long long int solve(int* a, int size, int n, int sub) {
  if (size == 0) return A;
  if (n == 0) return B;
  int k = 0;
  while (k < size && a[k] - sub < (1 << (n - 1))) k++;
  long long int ans = solve(a, k, n - 1, sub) +
                      solve(a + k, size - k, n - 1, sub + 1 << (n - 1));
  return min(ans, size * B * (1 << n));
}
int main() {
  int n, k;
  cin >> n >> k >> A >> B;
  int* a = new int[k];
  for (int i = 0; i < k; i++) scanf("%d", a + i);
  sort(a, a + k);
  cout << solve(a, k, n, 1) << '\n';
}
