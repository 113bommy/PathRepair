#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
} d[10007];
long long w, v, u, mx = -100000000000000000ll, mn = 100000000000000000ll, temp;
int main() {
  int n;
  cin >> n >> w >> v >> u;
  for (int i = 0; i < n; i++) {
    cin >> d[i].x >> d[i].y;
    temp = v * (w - d[i].y) + u * d[i].x;
    if (mx < temp) mx = temp;
    if (mn > temp) mn = temp;
  }
  if (mn >= w * v || n < 3)
    cout << fixed << setprecision(10) << (double)w / u << endl;
  else
    cout << fixed << setprecision(10) << (double)mx / (u * v) << endl;
}
