#include <bits/stdc++.h>
using namespace std;
int n;
char a[110];
int main() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i] - '0';
  }
  if (!sum) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 2; i <= sum; ++i) {
    if (sum % i) continue;
    int k = sum / i;
    int tmp = 0;
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      tmp += a[j] - '0';
      if (j == n) {
        if (tmp == k || (cnt == i) && tmp == 0) {
          cout << "YES" << endl;
          return 0;
        }
      } else {
        if (tmp == k) {
          cnt++;
          tmp = 0;
        } else if (tmp > k)
          break;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
