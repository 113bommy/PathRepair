#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i], a[i] %= m;
  if (n >= m) return cout << "YES", 0;
  set<int> b, c;
  for (long long i = 1; i <= n; i++) {
    int x = a[i];
    c = b;
    for (set<int>::iterator it = c.begin(); it != c.end(); it++)
      c.insert((*it + x) % m);
    b = c;
    b.insert(x);
  }
  if (b.find(0) != b.end())
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
