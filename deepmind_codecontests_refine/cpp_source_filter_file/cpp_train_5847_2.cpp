#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, dep, a[N];
string s;
int main() {
  cin >> n >> s;
  for (int i = 0; i <= n - 1; ++i) {
    if (s[i] == '(') {
      a[i] = ++dep;
    } else {
      a[i] = dep--;
    }
  }
  for (int i = 0; i <= n - 1; ++i) {
    cout << a[i] % 2 << ' ';
  }
  return 0;
}
