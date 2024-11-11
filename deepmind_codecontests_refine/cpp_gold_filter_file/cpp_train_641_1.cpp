#include <bits/stdc++.h>
using namespace std;
int m[1000];
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i < 1000; i++) m[i] = 0;
  m[0] = 1;
  int h = (a + b + c + d) / 2;
  for (int i = h; i >= 0; i--)
    if ((m[i] == 1) && (i + a <= h)) m[i + a] = 1;
  for (int i = h; i >= 0; i--)
    if ((m[i] == 1) && (i + b <= h)) m[i + b] = 1;
  for (int i = h; i >= 0; i--)
    if ((m[i] == 1) && (i + c <= h)) m[i + c] = 1;
  for (int i = h; i >= 0; i--)
    if ((m[i] == 1) && (i + d <= h)) m[i + d] = 1;
  int j = h;
  for (j = h; m[j] == 0; j--) {
  }
  if ((j == h) && ((a + b + c + d) % 2 == 0))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
