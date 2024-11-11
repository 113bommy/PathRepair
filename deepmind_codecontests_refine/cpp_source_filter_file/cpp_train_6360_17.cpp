#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
string a, b;
int main() {
  int n;
  cin >> n;
  cin >> a >> b;
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0' && b[i] == '0') a1++;
    if (a[i] == '1' && b[i] == '0') a2++;
    if (a[i] == '1' && b[i] == '1') a3++;
    if (a[i] == '0' && b[i] == '1') a4++;
  }
  long long ans = a1 * (a2 + a3) + a2 * a4;
  cout << ans << endl;
  return 0;
}
