#include <bits/stdc++.h>
using namespace std;
long long int v[100100], c[100100], prevv[100100], precc[100100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    c[i] = v[i];
  }
  sort(c, c + n);
  prevv[0] = v[0];
  precc[0] = c[0];
  for (int i = 1; i < n; i++) {
    prevv[i] = prevv[i - 1] + v[i];
    precc[i] = precc[i - 1] + c[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> t >> a >> b;
    a--;
    b--;
    if (t == 1) {
      if (a == 0) {
        cout << prevv[b] << endl;
      } else
        cout << prevv[b] - prevv[a - 1] << endl;
    } else if (t == 2) {
      if (a == 0) {
        cout << precc[b] << endl;
      } else
        cout << precc[b] - precc[a - 1] << endl;
    }
  }
  return 0;
}
