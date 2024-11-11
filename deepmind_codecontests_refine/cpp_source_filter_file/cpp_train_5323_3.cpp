#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j = 0, a = 0, s = 0, sum = 0, m;
  cin >> n;
  s = (n / 7) * 7;
  while ((n - s) % 4 != 0) {
    s -= 7;
    if (s < 0) {
      cout << "-1";
      return 0;
    }
  }
  a = (n - s) / 4;
  s /= 7;
  for (int i = 0; i < a; i++) cout << 4;
  for (int i = 0; i < s / 10; i++) cout << "77777777";
  for (int i = 0; i < s % 10; i++) cout << "7";
  return 0;
}
