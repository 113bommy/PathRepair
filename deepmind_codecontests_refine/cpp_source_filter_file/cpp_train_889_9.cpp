#include <bits/stdc++.h>
using namespace std;
int n, m, a, b[101];
void read() {
  int c, d, k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a, b[i] = a + b[i - 1];
  for (int i = 0; i < m; i++) {
    cin >> c >> d;
    k += (b[d] - b[c - 1] > 0 ? b[d] - b[c - 1] : 0);
  }
  cout << k;
}
int main() { read(); }
