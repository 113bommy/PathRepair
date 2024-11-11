#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int l, r;
int s[200];
int a[200];
int main() {
  cin >> n >> m;
  while (n--) {
    cin >> l >> r;
    s[l + 1]++;
    s[r + 2]--;
  }
  a[0] = 0;
  for (int i = 1; i <= m + 1; i++) {
    a[i] = a[i - 1] + s[i];
    if (!a[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
