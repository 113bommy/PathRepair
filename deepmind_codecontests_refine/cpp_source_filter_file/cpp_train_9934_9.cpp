#include <bits/stdc++.h>
using namespace std;
char a, b, c, d, a1, b1, c1, d1, l;
long long n, k, h, j, ans = 8, i;
int main() {
  cin >> a >> b >> l >> c >> d;
  cin >> a1 >> b1 >> l >> c1 >> d1;
  n = ((a - '0') * 10 + (b - '0')) * 60 + (c - '0') * 10 + (d - '0');
  k = ((a1 - '0') * 10 + (b1 - '0')) * 60 + (c1 - '0') * 10 + (d1 - '0');
  h = n - k;
  if (h < 0) h = 1439 - h - 60;
  if (h / 60 != 0 and h / 60 >= 10)
    cout << h / 60;
  else if (h / 60 < 10)
    cout << "0" << h / 60;
  cout << ":";
  if (h % 60 != 0 and h % 60 >= 10)
    cout << h % 60;
  else if (h % 60 < 10)
    cout << "0" << h % 60 << " ";
  return 0;
}
