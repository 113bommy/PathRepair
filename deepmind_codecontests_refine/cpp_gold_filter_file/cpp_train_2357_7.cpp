#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> v(6, n);
  vector<int> w = {a, a, a, a, b, b};
  sort(w.begin(), w.end(), greater<int>());
  int tem = 2 * a + b;
  if (tem <= n) {
    int ax = 1;
    tem *= 2;
    if (tem > n) ax++;
    cout << ax << endl;
    return 0;
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (v[j] >= w[i]) {
        v[j] -= w[i];
        break;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < 6; i++) {
    if (v[i] == n) cnt++;
  }
  cnt = 6 - cnt;
  cout << cnt << endl;
}
