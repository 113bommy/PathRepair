#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  string x;
  cin >> n >> a >> b;
  cin >> x;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == '0' && x[i + 1] != '0') cnt++;
  }
  if (a > b) {
    cout << b * cnt;
  } else if (cnt > 0) {
    cout << a * (cnt - 1) + b;
  } else
    cout << 0;
  return 0;
}
