#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, mx = 1, cnt = 1, x;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i += 1) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i += 1) {
    cnt = 1;
    x = v[i];
    while (x != -1) {
      cnt++;
      x = v[x - 1];
      mx = max(mx, cnt);
    }
  }
  cout << mx << endl;
}
