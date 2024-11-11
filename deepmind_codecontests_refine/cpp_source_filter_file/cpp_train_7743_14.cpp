#include <bits/stdc++.h>
using namespace std;
int n, k, m;
char a;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == '#') {
      m++;
      if (m >= k) {
        cout << n;
        return 0;
      }
    } else {
      m = 0;
    }
  }
  cout << "YES";
  return 0;
}
