#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, ta;
  int b, tb;
  cin >> a >> ta;
  cin >> b >> tb;
  int c, d;
  scanf("%d:%d", &c, &d);
  int atminutes = c * 60 + d;
  int adest = atminutes + ta;
  int ans = 0;
  for (int i = 30 * 10; i <= 1439; i += b) {
    if (i + tb > atminutes && i < adest) ans++;
  }
  cout << ans << endl;
  return 0;
}
