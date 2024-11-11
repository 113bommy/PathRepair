#include <bits/stdc++.h>
using namespace std;
long long arr[100000 + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int i = 0;
  int j = 1;
  int ans = min(2, n);
  int maxpr = 0;
  while (j <= n) {
    if (arr[j] > arr[j - 1]) {
      j++;
    } else {
      if (i > 1) {
        if (arr[i - 1] + 1 < arr[i + 1]) {
          if (maxpr + j - i > ans) ans = maxpr + j - i;
        } else if (arr[i - 2] + 1 < arr[i]) {
          if (maxpr + j - i + 1 > ans) ans = maxpr + j - i + 1;
        }
      }
      if (j < n) {
        if (j - i + 1 > ans) {
          ans = j - i + 1;
        }
      } else if (i - 1 >= 0) {
        if (j - i + 1 > ans) {
          ans = j - i + 1;
        }
      } else if (j - i > ans)
        ans = j - i;
      maxpr = j - i;
      i = j;
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
