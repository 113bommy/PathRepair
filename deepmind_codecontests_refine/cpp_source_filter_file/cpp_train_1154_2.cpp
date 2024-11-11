#include <bits/stdc++.h>
using namespace std;
int T[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += x;
    cout << sum / m - last << " ";
    last = sum / m;
  }
  return 0;
}
