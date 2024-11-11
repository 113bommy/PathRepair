#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i + 1 < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d[a]++;
    d[b]++;
  }
  cout << (count(d.begin(), d.end(), 2) ? "NO" : "YES") << endl;
  return 0;
}
