#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1);
  vector<int> seg(n * k + 1, 0);
  for (int i = 1; i <= k; i++) {
    cin >> v[i];
    seg[v[i]] = 1;
  }
  for (int i = 1; i <= k; i++) {
    cout << v[i] << " ";
    int t = 1;
    for (int j = 1; j <= n * k; j++) {
      if (t == n) break;
      if (seg[j] == 0) {
        cout << j << " ";
        seg[j] = 1;
        t++;
      }
    }
    cout << endl;
  }
}
