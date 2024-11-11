#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int main() {
  int n, m;
  cin >> n >> m;
  long long cou[N] = {};
  cou[0] = 1;
  for (int i = 1; i <= n; i++) cou[i] = cou[i - 1] * 2;
  vector<int> r;
  int t = 1;
  int u[N] = {};
  while (t < n) {
    if (cou[n - t - 1] < m) {
      t++;
      m -= cou[n - t];
    } else {
      r.push_back(t);
      u[t] = 1;
      t++;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (!u[i]) r.push_back(i);
  }
  for (int i = 0; i < n; i++) cout << r[i] << " ";
}
