#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  bool p = 0;
  for (int i = 0; i <= n / 1234567; i++) {
    for (int j = 0; j <= n / 123456; j++) {
      if (((n - i * 1234567 - j * 123456) % 1234 == 0) &&
          (n - i * 1234567 - j * 123456) > 0)
        p = 1;
    }
  }
  if (p == 1)
    cout << "YES";
  else
    cout << "NO";
}
