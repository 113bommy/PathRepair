#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int d[101];
  memset(d, -1, sizeof(a));
  for (int i = 0; i < a; ++i) {
    int c;
    cin >> c;
    d[c] = 1;
  }
  for (int i = 0; i < b; ++i) {
    int c;
    cin >> c;
    d[c] = max(d[c], 0);
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 1)
      cout << 1 << " ";
    else
      cout << 2 << " ";
  }
  cout << "\n";
}
