#include <bits/stdc++.h>
using namespace std;
int main() {
  const int SIZE = 500000, CACHE_SIZE = 1000;
  vector<int> a(SIZE + 1, 0);
  vector<vector<int>> cache(CACHE_SIZE, vector<int>(CACHE_SIZE, 0));
  int q;
  cin >> q;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int mod = 1; mod < CACHE_SIZE; mod++) cache[mod][x % mod] += y;
    } else {
      if (x < CACHE_SIZE) {
        cout << cache[x][y] << endl;
      } else {
        int sum = 0;
        for (int i = y; i < SIZE; i += x) sum += a[i];
        cout << sum << endl;
      }
    }
  }
}
