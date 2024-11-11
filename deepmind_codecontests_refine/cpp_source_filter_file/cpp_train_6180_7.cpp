#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a, a + 3);
  int u = 0;
  for (int i = 0; i < 4; i++)
    if (a[i] == a[i + 1]) u++;
  cout << u;
}
