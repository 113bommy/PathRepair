#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> nums[i];
  while (m-- > 0) {
    int l, r, x;
    cin >> l >> r >> x;
    int a = x - l;
    int b = 0;
    for (int i = l; i <= r; i++)
      if (nums[i] < nums[x]) b++;
    if (a != b)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
