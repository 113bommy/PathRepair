#include <bits/stdc++.h>
using namespace std;
int n, a[100001];
int n25, n50, n100, success;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 25) {
      n25++;
      success++;
    }
    if (a[i] == 50) {
      if (n25 > 0) {
        n25--;
        n50++;
        success++;
      }
    }
    if (a[i] == 100) {
      if (n25 == 1 && n50 == 1) {
        n50--;
        n25--;
        n100++;
        success++;
      } else if (n25 == 3) {
        n25 -= 3;
        n100++;
        success++;
      }
    }
  }
  if (success == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
