#include <bits/stdc++.h>
using namespace std;
int a[7];
long long ans;
int main() {
  for (int i = 0; i < 6; i++) cin >> a[i];
  for (int i = 0; i < min(a[1], a[5]); i++) ans += (i + a[0]) * 2 + 1;
  for (int i = 0; i < min(a[2], a[4]); i++) ans += (i + a[3]) * 2 + 1;
  for (int i = 0; i < a[1] + a[2] - min(a[1], a[5]) - min(a[4], a[2]); i++)
    ans += (a[3] + min(a[2], a[4])) * 2;
  cout << ans;
  return 0;
}
