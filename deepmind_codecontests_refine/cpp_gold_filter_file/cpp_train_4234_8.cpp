#include <bits/stdc++.h>
using namespace std;
int a[15], b[15], c[15], d[15];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  if (m < n || m > n) {
    cout << "No" << endl;
    return;
  } else {
    cout << "Yes" << endl;
    return;
  }
}
int main() { solve(); }
