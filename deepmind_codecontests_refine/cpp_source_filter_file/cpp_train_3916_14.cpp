#include <bits/stdc++.h>
using namespace std;
long int n;
long int a[10000];
int k;
int main() {
  int s = 0;
  int t = 0;
  int r = 0;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    t += a[i];
    if (a[i] % 2 == 1) {
      s++;
    }
    if (a[i] % 4 == 2) {
      r++;
    }
  }
  t += s;
  if (t > 8 * n) {
    cout << "NO";
  } else {
    if (s >= n) {
      cout << "YES";
    } else {
      if (r > 2 * n + s + 1) {
        if (t + 2 * (r - 2 * n - s) > 8 * n) {
          cout << "NO";
        } else {
          cout << "YES";
        }
      } else {
        cout << "YES";
      }
    }
  }
  return 0;
}
