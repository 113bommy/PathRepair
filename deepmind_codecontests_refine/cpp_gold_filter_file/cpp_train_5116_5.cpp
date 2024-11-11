#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, h, i, j, k = 0, tmp;
  multiset<int> m;
  m.insert(-1);
  m.insert(-1);
  cin >> n >> h;
  for (i = 0; i < n; ++i) {
    cin >> tmp;
    m.insert(tmp);
    long long sum = 0;
    auto it = m.rbegin();
    while (*it != -1) {
      sum += *it;
      advance(it, 2);
    }
    if (sum <= h) {
      ++k;
    }
  }
  cout << k << endl;
  return 0;
}
