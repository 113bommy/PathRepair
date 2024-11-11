#include <bits/stdc++.h>
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  optimizeIO();
  int n, c = 0;
  cin >> n;
  for (typeof(n) i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) c++;
  }
  if (n == 1) {
    if (c == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    if (c == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
