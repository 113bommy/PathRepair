#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, ans = 0;
  std::cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  bool ok = true;
  for (i = 0; i < n - 1; i++) {
    if (a[i] == 2 && a[i + 1] == 3 || a[i] == 3 && a[i + 1] == 2) {
      ok = false;
      break;
    }
    if (a[i] == 1 && a[i + 1] == 2 || a[i] == 2 && a[i + 1] == 1) {
      if (i > 0 && a[i] == 1 && a[i + 1] == 2) {
        if (a[i - 1] == 3) {
          ans += 2;
        } else {
          ans += 3;
        }
      } else {
        ans += 3;
      }
    }
    if (a[i] == 1 && a[i + 1] == 3 || a[i] == 3 && a[i + 1] == 1) {
      ans += 4;
    }
  }
  if (ok) {
    std::cout << "Finite" << std::endl;
    cout << ans << "\n";
  } else {
    std::cout << "Infinite" << std::endl;
  }
  return 0;
}
