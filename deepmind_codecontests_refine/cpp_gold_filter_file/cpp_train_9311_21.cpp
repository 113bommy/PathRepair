#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, maxi = 0;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  vector<int> a(n, 0);
  vector<int> right(n, 0);
  vector<int> left(n, 0);
  vector<int> ans(n, 0);
  for (i = 0; i < n; i++) scanf(" %d", &a[i]);
  for (i = 1; i < n; i++)
    if (a[i] > a[i - 1]) left[i] += left[i - 1] + 1;
  for (i = n - 2; i >= 0; i--)
    if (a[i] < a[i + 1]) right[i] += right[i + 1] + 1;
  for (i = 1; i < n - 1; i++) {
    if (a[i - 1] < a[i] && a[i] < a[i + 1])
      ans[i] = left[i] + right[i] + 1;
    else if (a[i + 1] > a[i - 1] + 1)
      ans[i] = left[i - 1] + right[i + 1] + 3;
    else
      ans[i] = max(left[i - 1], right[i + 1]) + 2;
  }
  ans[0] = (a[0] < a[1]) ? right[0] + 1 : right[1] + 2;
  ans[n - 1] = (a[n - 1] > a[n - 2]) ? left[n - 1] + 1 : left[n - 2] + 2;
  for (i = 0; i < n; i++)
    if (ans[i] > maxi) maxi = ans[i];
  cout << maxi << endl;
}
