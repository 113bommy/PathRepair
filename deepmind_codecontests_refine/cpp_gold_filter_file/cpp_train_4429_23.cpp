#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  int p[n], t[n];
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  int l = 0, r = 0;
  for (int i = 0, x = 0; i < n; i++) {
    x += t[i];
    l += max(0, p[i] - c * x);
  }
  for (int i = n - 1, x = 0; i >= 0; i--) {
    x += t[i];
    r += max(0, p[i] - c * x);
  }
  if (l > r)
    cout << "Limak\n";
  else if (r > l)
    cout << "Radewoosh\n";
  else
    cout << "Tie\n";
  return 0;
}
