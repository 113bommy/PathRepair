#include <bits/stdc++.h>
using namespace std;
int a, b, c, l;
int main() {
  cin >> a >> b >> c >> l;
  long long ans = (l + 1) * (l + 2) * (l + 3) / 6;
  long long temp = 0;
  for (int i = 0; i <= l; i++) {
    long long x = min(a - b - c + i, l - i);
    if (x < 0) continue;
    temp += (x + 1) * (x + 2) / 2;
  }
  for (int i = 0; i <= l; i++) {
    long long x = min(b - a - c + i, l - i);
    if (x < 0) continue;
    temp += (x + 1) * (x + 2) / 2;
  }
  for (int i = 0; i <= l; i++) {
    long long x = min(c - a - b + i, l - i);
    if (x < 0) continue;
    temp += (x + 1) * (x + 2) / 2;
  }
  cout << ans - temp << endl;
}
