#include <bits/stdc++.h>
using namespace std;
int aa, bb, cc;
bool canwin(int a, int b, int c) {
  int i = max(0, b - cc);
  int j = max(0, bb - c);
  if (!i) return 0;
  if (i && !j) return 1;
  int z = (aa + i - 1) / i;
  return (a - z * j > 0);
}
int main() {
  int mn = 9999999, a, b, c, pa, pb, pc;
  cin >> a >> b >> c >> aa >> bb >> cc >> pa >> pb >> pc;
  for (int i = a; i <= 1000; i++)
    for (int j = b; j < 201; j++)
      for (int k = c; k < 201; k++)
        if (canwin(i, j, k))
          mn = min(mn, pa * (i - a) + pb * (j - b) + pc * (k - c));
  cout << mn << endl;
  return 0;
}
