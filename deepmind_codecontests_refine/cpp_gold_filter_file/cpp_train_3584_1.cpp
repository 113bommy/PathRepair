#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    printf("1 2 3\n1 3 3\n2 4 2\n4 5 1\n");
    printf("3 4\n3 5\n");
    return 0;
  }
  int p = n / 2;
  for (int i = 1; i < n - p; i++)
    printf("%d %d %d\n", i, i + 1, max(1, 2 * (p - i) - 1));
  for (int i = p; i >= 1; i--) printf("%d %d %d\n", i, i + n - p, 1);
  cout << n - 2 << " " << n << endl;
  for (int i = n - p + 1; i < n; i++) printf("%d %d\n", i, i + 1);
  return 0;
}
