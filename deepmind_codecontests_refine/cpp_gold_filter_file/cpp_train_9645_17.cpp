#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0, i, a;
bool c[601];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (c[a] == 0 && a != 0) {
      c[a] = 1;
      cnt++;
    }
  }
  cout << cnt;
}
