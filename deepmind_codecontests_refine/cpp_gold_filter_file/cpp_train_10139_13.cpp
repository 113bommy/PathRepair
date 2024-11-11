#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int m = 0, n = 0;
  cin >> m >> n;
  if (m % n == 0) {
    for (int i = 1; i <= n; i++) cout << m / n << " ";
    cout << endl;
  } else {
    int t1 = m / n, t2 = m / n + 1;
    for (int i = 1; i <= n; i++) {
      if (i * t2 + (n - i) * t1 == m) {
        for (int j = 1; j <= n - i; j++) cout << t1 << " ";
        for (int j = 1; j <= i; j++) cout << t2 << " ";
        cout << endl;
        break;
      }
    }
  }
  return EXIT_SUCCESS;
}
