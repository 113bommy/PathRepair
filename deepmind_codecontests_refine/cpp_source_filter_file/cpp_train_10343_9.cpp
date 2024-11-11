#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, a[199];
  cin >> x;
  if (x == 3) {
    cout << 5;
    return 0;
  }
  for (int i = 1; i < 20; i++)
    if (i % 2 == 0)
      a[i] = i;
    else
      a[i] = (i * i + 1) / 2;
  int res = 1;
  while (res < 20) {
    if (a[res] >= x) break;
    res++;
  }
  cout << res;
  return 0;
}
