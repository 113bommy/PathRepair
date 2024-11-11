#include <bits/stdc++.h>
using namespace std;
int n, q;
bool a[2][100000];
int cnt1, cnt2;
int main() {
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    if (a[0][c] && a[1][c]) {
      cnt1--;
    }
    if (c > 0 && ((a[0][c] && a[1][c - 1]) || (a[1][c] && a[0][c - 1]))) {
      cnt2--;
    }
    if (c < n - 1 && ((a[0][c] && a[1][c + 1]) || (a[1][c] && a[0][c + 1]))) {
      cnt2--;
    }
    a[r][c] = !a[r][c];
    if (a[0][c] && a[1][c]) {
      cnt1++;
    }
    if (c > 0 && ((a[0][c] && a[1][c - 1]) || (a[1][c] && a[0][c - 1]))) {
      cnt2++;
    }
    if (c < n - 1 && ((a[0][c] && a[1][c + 1]) || (a[1][c] && a[0][c + 1]))) {
      cnt2++;
    }
    if (cnt1 + cnt2) {
      cout << "No\n";
    } else
      cout << "Yes\n";
  }
}
