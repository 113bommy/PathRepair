#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num[n], i, j, x;
  int a[1001];
  for (i = 0; i < 1001; i++) a[i] = -1;
  for (i = 0; i < n; i++) {
    cin >> num[i];
    a[num[i]] = i + 1;
  }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      x = num[i] + num[j];
      if (a[x] != -1) {
        cout << a[x] << ' ' << i + 1 << ' ' << j + 1;
        return 0;
      }
    }
  cout << "-1";
  return 0;
}
