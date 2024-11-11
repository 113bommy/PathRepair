#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, s = 0;
  cin >> n >> k;
  string sa;
  cin >> sa;
  int a[25];
  for (int i = 0; i < n; i++) {
    a[sa.at(i) - 97] = 1;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] == 1) {
      s = s + i + 1;
      k--;
      i = i + 1;
    }
    if (k == 0) break;
  }
  if (k != 0)
    cout << -1 << endl;
  else
    cout << s << endl;
  return 0;
}
