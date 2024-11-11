#include <bits/stdc++.h>
using namespace std;
unsigned long long get(unsigned long long x) {
  if (x == 1) return 1;
  if (x == 2) return 2;
  if (x & 1) {
    x++;
    x /= 2;
    return 2 * x * x;
  } else {
    x /= 2;
    return 2 * x * x + x + 1;
  }
}
int main() {
  unsigned long long n, m;
  cin >> n >> m;
  vector<unsigned long long> in(m);
  for (int i = 0; i < m; i++) cin >> in[i], cin >> in[i];
  sort(in.rbegin(), in.rend());
  unsigned long long sm = in[0];
  for (int i = 2; i <= m; i++) {
    if (get(i) > n) break;
    sm += in[i - 1];
  }
  cout << sm << endl;
  return 0;
}
