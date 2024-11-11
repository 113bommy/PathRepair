#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  int n = 0, sum = 0;
  static int a[50];
  while (T) a[n++] = T % 3, T /= 3, sum += 2 - a[n - 1];
  cout << n + 3 << ' ' << n + 3 << endl;
  cout << (n > 1 ? (6 * n + sum - 6) : 4) << endl;
  for (int i = 1; i < n; ++i)
    printf("%d %d %d %d\n%d %d %d %d\n", i, i + 3, i + 1, i + 3, i + 3, i,
           i + 3, i + 1);
  printf("%d %d %d %d\n", n + 2, n + 2, n + 2, n + 3);
  printf("%d %d %d %d\n", n + 2, n + 2, n + 3, n + 2);
  printf("%d %d %d %d\n", n + 2, n + 1, n + 3, n + 1);
  printf("%d %d %d %d\n", n + 1, n + 2, n + 1, n + 3);
  for (int i = 1; i < n - 1; ++i)
    printf("%d %d %d %d\n%d %d %d %d\n", i, i + 5, i + 1, i + 5, i + 5, i,
           i + 5, i + 1);
  for (int i = 1; i < n - 1; ++i)
    printf("%d %d %d %d\n%d %d %d %d\n", i, i + 4, i, i + 5, i + 4, i, i + 5,
           i);
  for (int i = 0; i < n; ++i) {
    if (a[i] < 2) printf("%d %d %d %d\n", i + 1, i + 3, i + 1, i + 4);
    if (a[i] < 1) printf("%d %d %d %d\n", i + 3, i + 1, i + 4, i + 1);
  }
  return 0;
}
