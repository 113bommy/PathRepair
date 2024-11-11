#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 7;
int a[Max];
int fen[Max];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fen[i] = a[i] - a[i - 1];
    if (fen[i] > 0 && i != 1) {
      sum += fen[i];
    }
  }
  cout << max((sum + fen[1]) / 2, (sum + fen[1]) - (sum + fen[1]) / 2) << '\n';
  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    if (l == 1) {
      fen[1] += x;
    } else {
      if (fen[l] > 0) {
        sum -= fen[l];
      }
      fen[l] += x;
      if (fen[l] > 0) {
        sum += fen[l];
      }
    }
    if (r + 1 <= n) {
      if (fen[r + 1] > 0) {
        sum -= fen[r + 1];
      }
      fen[r + 1] -= x;
      if (fen[r + 1] > 0) {
        sum += fen[r + 1];
      }
    }
    cout << max((sum + fen[1]) / 2, (sum + fen[1]) - (sum + fen[1]) / 2)
         << '\n';
  }
  return 0;
}
