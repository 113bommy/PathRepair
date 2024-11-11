#include <bits/stdc++.h>
using namespace std;
int n;
int p[100] = {};
int t = 0, odd = 0;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] % 2 == 1) {
      t = i;
      odd++;
    }
  }
  if (odd > 1) {
    cout << 0 << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= p[i]; j++) {
        cout << char(i + 'a' - 1);
      }
    }
    cout << endl;
    return;
  } else if (odd == 1) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i == t)
        ans = gcd(p[i], ans);
      else
        ans = gcd(p[i] / 2, ans);
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= p[j] / ans / 2; k++) {
          cout << char(j + 'a' - 1);
        }
      }
      cout << char('a' + t - 1);
      for (int j = n; j > 0; j--) {
        for (int k = 1; k <= p[j] / ans / 2; k++) {
          cout << char('a' + j - 1);
        }
      }
    }
    cout << endl;
  } else {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = gcd(p[i], ans);
    }
    cout << ans << endl;
    for (int i = 1; i <= ans / 2; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= p[j] / ans; k++) {
          cout << char('a' + j - 1);
        }
      }
      for (int j = n; j > 0; j--) {
        for (int k = 1; k <= p[j] / ans; k++) {
          cout << char('a' + j - 1);
        }
      }
    }
    cout << endl;
  }
}
int main() {
  init();
  return 0;
}
