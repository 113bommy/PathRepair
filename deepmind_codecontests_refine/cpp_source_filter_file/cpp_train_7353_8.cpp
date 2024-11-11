#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    if (n % 2) {
      printf("%s\n", "Conan");
      continue;
    }
    int ok = 1;
    for (int i = 0; i <= n - 2; i++) {
      if (a[i] != a[i + 1]) {
        ok = 0;
        break;
      }
    }
    if (ok)
      cout << "Agasa" << endl;
    else
      cout << "Conan" << endl;
  }
  return 0;
}
