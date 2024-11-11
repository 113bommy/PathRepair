#include <bits/stdc++.h>
using namespace std;
const bool CODEFORCES = true;
int sum[200010];
int main() {
  if (!CODEFORCES) {
#pragma warning(disable : 4996)
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  string a, b;
  cin >> a >> b;
  long long ans = 0;
  int lna = a.length();
  int lnb = b.length();
  for (int i = 0; i < (lnb - lna) + 1; i++) sum[0] += (int(b[i]) - 48);
  for (int i = 1; i < lna; i++)
    sum[i] = sum[i - 1] + (int(b[lnb - lna + i]) - 48) - (int(b[i - 1]) - 48);
  for (int i = 0; i < lna; i++) {
    if (int(a[i]) - 48 == 0)
      ans += sum[i];
    else
      ans += ((lnb - lna) + 1) - sum[i];
  }
  cout << ans;
}
