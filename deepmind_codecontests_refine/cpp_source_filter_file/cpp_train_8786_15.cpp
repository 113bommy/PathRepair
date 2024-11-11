#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
int sm(int n) {
  int s = 0;
  while (n) {
    s += (n % 10);
    n /= 10;
  }
  return s;
}
int sum(vector<int> &v, int i, int j) {
  int s = 0;
  if (j == 0) return v[0];
  for (int k = i; k < j; ++k) {
    s += v[k];
  }
  return s;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int m, x, y;
  cin >> m;
  vector<int> v(m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
  }
  cin >> x >> y;
  for (int i = 0; i < m; ++i) {
    int a = sum(v, 0, i);
    int b = sum(v, i, m);
    if (a >= x && a <= y && b >= x && b <= y) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
