#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("data.txt");
  int i, j, t, m, k;
  long long n, d1, d2, tk, tmp = 0, mx = -1, mn = -1;
  int a, b, c;
  cin >> n >> m;
  vector<int> v(n);
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    v[a]++;
    v[b]++;
  }
  for (i = 0; i < n; i++) {
    if (v[i] == 0) t = i;
  }
  t++;
  cout << n - 1 << endl;
  for (i = 1; i <= n; i++) {
    if (i != t) cout << t << " " << i << endl;
  }
  return 0;
}
