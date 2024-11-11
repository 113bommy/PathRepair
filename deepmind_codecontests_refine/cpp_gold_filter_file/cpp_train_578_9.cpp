#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
int a[maxn], b;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b;
    if (i < l or i > r) {
      if (a[i] != b) {
        cout << "LIE";
        return 0;
      }
    }
  }
  cout << "TRUTH";
  return 0;
}
