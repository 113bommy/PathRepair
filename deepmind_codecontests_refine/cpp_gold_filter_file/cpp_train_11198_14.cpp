#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, mini = 2e9;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    mini = min(mini, r - l + 1);
  }
  cout << mini << endl;
  for (int i = 0; i < n; i++) {
    cout << i % mini << ' ';
  }
}
