#include <bits/stdc++.h>
using namespace std;
int main() {
  int my[3], rec[3];
  for (int i = 0; i < 3; i++) cin >> my[i];
  for (int i = 0; i < 3; i++) cin >> rec[3];
  int a[6];
  for (int i = 0; i < 6; i++) cin >> a[i];
  int ans = 0;
  if (my[0] > rec[0]) ans += a[5];
  if (my[0] < 0) ans += a[4];
  if (my[1] > rec[1]) ans += a[1];
  if (my[1] < 0) ans += a[0];
  if (my[2] > rec[2]) ans += a[3];
  if (my[2] < 0) ans += a[2];
  cout << ans << endl;
  return 0;
}
