#include <bits/stdc++.h>
int nums[100002], fl[100002], fr[100002];
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
  fl[0] = fr[n - 1] = 1;
  for (int i = 1; i < n - 1; i++) {
    fl[i] = min(fl[i - 1] + 1, nums[i]);
    fr[n - i - 1] = min(fr[n - i] + 1, nums[n - i - 1]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, min(fl[i], fr[i]));
  cout << ans << endl;
  return 0;
}
