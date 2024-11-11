#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.length(), m = b.length();
  int c = 0;
  for (int i = 0; i < min(n, m); i++) {
    if (a[i] == b[i]) {
      c++;
    }
  }
  if (max(n, m) - c == 0) {
    cout << -1;
  } else {
    cout << max(n, m);
  }
  return 0;
}
