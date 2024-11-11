#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
int a[maxn];
int main() {
  bool b = true;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (a[0] != 0) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        a[i]--;
        if (a[i] == -1) a[i] = n - 1;
      } else {
        a[i]++;
        if (a[i] == n) a[i] = 0;
      }
    }
  }
  for (int i = 1; i < n; i++)
    if (a[i - 1] >= a[i]) b = false;
  if (b)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
