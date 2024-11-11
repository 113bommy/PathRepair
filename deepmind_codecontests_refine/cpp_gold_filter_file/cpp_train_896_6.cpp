#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int l = 0;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (l < a) {
      cout << "NO";
      return 0;
    } else {
      l = max(b, l);
    }
  }
  if (l >= m) {
    cout << "YES";
    return 0;
  } else {
    cout << "NO";
    return 0;
  }
  return 0;
}
