#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 3005;
int n;
char a[kMaxN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i];
    if (!(i % 2) && i != n && i != n - 1) {
      cout << '-';
    }
  }
  return 0;
}
