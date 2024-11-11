#include <bits/stdc++.h>
using namespace std;
void sove() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  int i = n - 1, j = m - 1;
  while (i >= 0 && j >= 0) {
    if (a[i] == b[j]) {
      i--;
      j--;
    } else {
      i -= 2;
    }
  }
  if (j == -1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) sove();
  return 0;
}
