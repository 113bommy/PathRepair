#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, a, b;
bool vis[N];
void solve() { return; }
int main() {
  int _;
  cin >> _;
  while (_--) {
    cin >> a >> b;
    n = a + b;
    for (int i = 0; i <= n; i++) vis[i] = false;
    int A = n / 2, B = n - A, Min;
    if (a <= B)
      Min = 0;
    else
      Min = a - B;
    for (int i = Min; i <= min(a, A); i++) {
      int lop = 0;
      lop += A - i;
      lop += a - i;
      vis[lop] = true;
    }
    if (n % 2 == 1) {
      A = n / 2 + 1;
      B = n - A;
      if (a <= B)
        Min = 0;
      else
        Min = a - B;
      for (int i = Min; i <= min(a, A); i++) {
        int lop = 0;
        lop += A - i;
        lop += a - i;
        vis[lop] = true;
      }
      B = n / 2 + 1;
      A = n - A;
      if (a <= B)
        Min = 0;
      else
        Min = a - B;
      for (int i = Min; i <= min(a, A); i++) {
        int lop = 0;
        lop += A - i;
        lop += a - i;
        vis[lop] = true;
      }
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
      if (vis[i]) sum++;
    }
    cout << sum << endl;
    for (int i = 0; i <= n; i++) {
      if (vis[i]) cout << i << " ";
    }
    if (sum != 0) cout << endl;
  }
  return 0;
}
