#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  long long ans = 0;
  long long res[10];
  for (int a = 1; a < 10; a++) {
    long long s = 0;
    for (int b = 1; b < n + 1; b++) {
      int c = a * b;
      int resto = (c - 1) % 9 + 1;
      s += (n + 9 - resto) / 9 - 1;
    }
    res[a] = s;
  }
  res[0] = res[9];
  for (int a = 1; a < n + 1; a++) {
    ans += res[a % 9];
    ans += n - n / a;
  }
  cout << ans << endl;
}
