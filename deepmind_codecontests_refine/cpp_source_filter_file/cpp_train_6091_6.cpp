#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int sz;
  vector<long long> a;
  BIT() { sz = 0; }
  BIT(int n) {
    sz = n + 9;
    a.resize(n + 10, 0);
  }
  void update(int ind, long long x) {
    int i = ind;
    while (i < sz) {
      a[i] += x;
      i += (i & -i);
    }
  }
  long long query(int ind) {
    int i = ind;
    long long res = 0;
    while (i > 0) {
      res += a[i];
      i -= (i & -i);
    }
    return res;
  }
  long long getSuf(int ind) { return query(sz) - query(ind); }
};
BIT arr[12];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k + 1; i++) {
    arr[i] = BIT(n + 1);
  }
  int x;
  vector<int> a(n + 10);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    long long x = a[i];
    arr[1].update(x, 1);
    for (int j = 2; j <= k + 1; j++) {
      long long res = arr[j - 1].getSuf(x);
      arr[j].update(x, res);
    }
  }
  long long res = arr[k + 1].getSuf(0);
  cout << res << "\n";
}
