#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, x, y, z, k, l, o, p;
vector<long long> a, b;
bool u;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
    u = 1;
  }
  l = 0;
  long long o = 0;
  while (l < n + m) {
    o++;
    l += o;
  }
  for (i = o; i > 0; i--)
    if (n - i >= 0) {
      a.push_back(i);
      n -= i;
    } else if (m - i >= 0) {
      m -= i;
      b.push_back(i);
    }
  if (u) {
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
    if (b.size() > 0) cout << "\n";
    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  } else {
    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    if (a.size() > 0) cout << "\n";
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
  }
  return 0;
}
