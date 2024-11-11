#include <bits/stdc++.h>
using namespace std;
int main() {
  int tests;
  cin >> tests;
  for (int idk = 0; idk < tests; idk++) {
    long long n;
    cin >> n;
    long long a[n], one = 0, md1 = 0, md2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) one = 1;
      if (a[i] % 3 == 1) md1 = 1;
      if (a[i] % 3 == 2) md2 = 1;
    }
    std::sort(a, a + n);
    int dif1 = 0;
    for (int i = 0; i < n; i++)
      if (a[n - 1] - a[i] == 1) dif1 = 1;
    long long ans[4];
    ans[1] = 0;
    ans[2] = 0;
    if (md1) ans[1] = 1;
    if (md2) ans[2] = 1;
    if ((md1) && (md2) && (one == 0) && (a[n - 1] % 3 == 1) && (dif1 == 0)) {
      ans[1] = 0;
      ans[2] = 2;
    }
    long long dif = ans[1] + ans[2] * 2;
    ans[3] = 0;
    for (int i = 0; i < n; i++) {
      ans[3] = max(ans[3], (a[i] + 2 - dif) / 3);
    }
    cout << ans[1] + ans[2] + ans[3] << endl;
  }
}
