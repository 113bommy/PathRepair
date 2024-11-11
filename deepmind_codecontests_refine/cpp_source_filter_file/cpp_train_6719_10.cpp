#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, arr;
  cin >> n >> arr;
  int a[n + 1];
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i];
  int left = arr - 1;
  int right = n - arr;
  int cnt = 0;
  if (a[arr] == 1) ++cnt;
  if (left < right) {
    int i = 1;
    while (i <= left) {
      int num1 = a[arr - i];
      int num2 = a[arr + i];
      if (num1 == 1 && num2 == 1) cnt += 2;
      ++i;
    }
    for (int j = arr + left + 1; j <= n; j++)
      if (a[j] == 1) ++cnt;
    cout << cnt << '\n';
  } else {
    int i = 1;
    while (i <= right) {
      int num1 = a[arr - i];
      int num2 = a[arr + i];
      if (num1 == 1 && num2 == 1) cnt += 2;
      ++i;
    }
    for (int j = 1; j < arr + right; j++)
      if (a[j] == 1) ++cnt;
    cout << cnt << '\n';
  }
  return 0;
}
