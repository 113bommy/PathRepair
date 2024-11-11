#include <bits/stdc++.h>
using namespace std;
long long const INF = 2000000000;
long long const MAXN = 50001;
long long const P = 100000000000;
int table[11][11];
int p;
void convert(int x, int p) {
  ++p;
  vector<int> res;
  while (x > p) {
    res.push_back(x % p);
    x /= p;
  }
  res.push_back(x);
  for (int i = res.size() - 1; i >= 0; --i) {
    cout << res[i];
  }
}
int main() {
  cin >> p;
  --p;
  for (int i = 1; i <= p; ++i)
    for (int j = 1; j <= p; ++j) {
      table[i - 1][j - 1] = (i) * (j);
    }
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < p; ++j) {
      convert(table[i][j], p);
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}
