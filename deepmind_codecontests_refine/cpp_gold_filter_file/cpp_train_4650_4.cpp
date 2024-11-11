#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  multiset<int> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    m.insert(abs(a[i] - b[i]));
  }
  for (int i = 0; i < k1 + k2; i++) {
    auto it = m.end();
    it--;
    int df = *it;
    m.erase(it);
    df = abs(df - 1);
    m.insert(df);
  }
  long long e = 0;
  for (auto i : m) {
    e += 1LL * i * i;
  }
  cout << e << endl;
  return 0;
}
