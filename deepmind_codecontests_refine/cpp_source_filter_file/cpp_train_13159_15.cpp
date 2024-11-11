#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  int trolley = 0;
  int trolley1 = 0;
  int bus = 0;
  int bus1 = 0;
  for (int i = 0; i < n; ++i) bus = bus + a[i] * c1;
  bus1 = bus;
  for (int i = 0; i < m; ++i) trolley = trolley + b[i] * c1;
  trolley1 = trolley;
  for (int i = 0; i < n; ++i) {
    int s = bus1 - a[i] * c1 + c2;
    if (s < bus) bus = s;
  }
  for (int i = 0; i < m; ++i) {
    int s = trolley1 - b[i] * c1 + c2;
    if (s < trolley) trolley = s;
  }
  if (c3 < trolley) trolley = c3;
  if (bus > c3) bus = c3;
  if ((bus + trolley) > c4)
    cout << c4;
  else
    cout << bus + trolley;
  return 0;
}
