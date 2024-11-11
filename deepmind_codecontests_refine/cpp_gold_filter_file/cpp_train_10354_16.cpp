#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, d, tem1, tem2, tem3, sum = 0, ans = 0;
  string s, c;
  cin >> n;
  cin >> tem1;
  ans = tem1;
  tem2 = tem1;
  int eng = 0;
  for (int i = 2; i <= n; i++) {
    cin >> tem1;
    if (tem2 - tem1 < 0 && tem1 - tem2 > eng) {
      ans += (abs(tem2 - tem1) - eng);
      eng = 0;
    } else {
      eng += tem2 - tem1;
    }
    tem2 = tem1;
  }
  cout << ans;
  return 0;
}
