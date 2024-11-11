#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w, x, y, z;
  long long int max = 0;
  cin >> w;
  if (w > max) max = w;
  cin >> x;
  if (x > max) max = x;
  cin >> y;
  if (y > max) max = y;
  cin >> z;
  if (z > max) max = z;
  if (max != w) cout << max - w << " ";
  if (max != x) cout << max - x << " ";
  if (max != y) cout << max - y << " ";
  if (max != w) cout << max - z;
}
