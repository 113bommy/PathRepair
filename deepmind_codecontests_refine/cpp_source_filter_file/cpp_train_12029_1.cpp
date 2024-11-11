#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n;
  for (int i = 0; i <= 820; i++) {
    for (int j = 0; j <= 8100; j++) {
      if (((long long)n - i * 1234567 - j * 123456) % 1234 == 0 &&
          ((long long)n - i * 1234567 - j * 123456) / 1234 > 0) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
