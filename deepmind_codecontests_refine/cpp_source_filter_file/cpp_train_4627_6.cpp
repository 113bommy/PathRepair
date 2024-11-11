#include <bits/stdc++.h>
using namespace std;
int n, a[100000], d[10000], b, c, x, m, y;
int main() {
  cin >> n >> y;
  for (int i = 0; i < n; i++) cin >> a[i];
  x = y;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < i; j++)
      if ((int)(y / a[i]) * a[j] + y % a[i] > x)
        x = (y / a[i]) * a[j] + y % a[i];
  cout << x;
}
