#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int min1, min2, min3, max1, max2, max3;
  cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
  int c = n;
  int ans1 = min1, ans2 = min2, ans3 = min3;
  for (int i = min3; i < max3; i++) {
    if (ans1 + ans2 + ans3 == n) break;
    ans3++;
  }
  for (int i = min2; i < max2; i++) {
    if (ans1 + ans2 + ans3 == n) break;
    ans2++;
  }
  for (int i = min1; i < max1; i++) {
    if (ans1 + ans2 + ans3 == n) break;
    ans1++;
  }
  cout << ans1 << " " << ans2 << " " << ans3;
  return 0;
}
