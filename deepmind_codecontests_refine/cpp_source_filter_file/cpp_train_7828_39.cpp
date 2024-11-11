#include <bits/stdc++.h>
using namespace std;
int a[110];
int n, x, ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < 101; i++)
    for (int j = i + 1; j < 101; j++)
      if (a[i] > 1 && a[j] > 1) {
        ans++;
        a[i] -= 2;
        a[j] -= 2;
      }
  for (int i = 0; i < 101; i++)
    if (a[i] > 3) {
      ans++;
      a[i] -= 4;
    }
  cout << ans;
  return 0;
}
