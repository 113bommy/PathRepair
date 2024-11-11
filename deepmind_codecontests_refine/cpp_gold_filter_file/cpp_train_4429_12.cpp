#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 0, r = 0, c, T = 0, p[10001], t[10001];
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) {
    T += t[i];
    l += max(0, p[i] - c * T);
  }
  T = 0;
  for (int i = n - 1; i >= 0; i--) {
    T += t[i];
    r += max(0, p[i] - c * T);
  }
  if (l > r)
    cout << "Limak";
  else if (l < r)
    cout << "Radewoosh";
  else
    cout << "Tie";
  return 0;
}
