#include <bits/stdc++.h>
using namespace std;
const int N = 205000;
const int SQRTN = 320;
const int LOGN = 20;
const long double PI = acos(-1);
int a, b, ta, tb, hh, mm;
signed main() {
  cin >> a >> ta >> b >> tb;
  scanf(" %d:%d", &hh, &mm);
  mm += hh * 60;
  int ans = 0;
  for (int i = 300; i <= 1439; i += b)
    if (max(i, mm) < min(i + tb, mm + ta)) ans++;
  cout << ans << endl;
}
