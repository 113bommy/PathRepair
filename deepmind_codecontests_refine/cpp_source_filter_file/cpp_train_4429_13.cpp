#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, c;
  cin >> n >> c;
  int p[1002], t[1002];
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> t[i];
  int l = 0, r = 0;
  int time = 0;
  for (int i = 0; i < n; ++i) {
    time += t[i];
    l += max(0, p[i] - time * c);
  }
  time = 0;
  for (int i = n - 1; i > 0; --i) {
    time += t[i];
    r += max(0, p[i] - time * c);
  }
  if (l == r) {
    cout << "Tie\n";
  } else if (l > r)
    cout << "Limak\n";
  else
    cout << "Radewoosh\n";
  return 0;
}
