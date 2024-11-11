#include <bits/stdc++.h>
using namespace std;
int main() {
  string big, small;
  cin >> big >> small;
  int nums1 = 0;
  for (int i = 0; i < small.length(); i++)
    if (small[i] == '1') nums1++;
  for (int i = 0; i < small.length(); i++)
    if (big[i] == '1') nums1++;
  int ans = nums1 % 2 == 0;
  for (int i = small.length(); i < big.length(); i++) {
    if (big[i] == '1') nums1++;
    if (big[i - small.length()] == '1') nums1--;
    if (nums1 % 2 == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
