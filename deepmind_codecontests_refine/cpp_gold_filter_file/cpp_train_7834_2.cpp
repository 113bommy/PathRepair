#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const int inf = 1e9;
int main() {
  int n;
  scanf("%d", &n);
  int q;
  scanf("%d", &q);
  vector<int> End[n + 1], BIT(n + 1), ans(n), a(n + 1), Left(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = i - a[i];
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    int y;
    scanf("%d", &y);
    int l = 1 + x;
    int r = n - y;
    Left[i] = l;
    End[r].push_back(i);
  }
  int global = 0;
  for (int r = 1; r <= n; r++) {
    if (a[r] >= 0) {
      int pos = 0, cur = global;
      int Log = log2(n);
      for (int ind = Log; ind >= 0; ind--) {
        int jump = 1 << ind;
        if (pos + jump <= r and cur - BIT[pos + jump] >= a[r]) {
          pos += jump;
          cur -= BIT[pos];
        }
      }
      global++;
      for (int i = pos + 1; i <= n; i += i & -i) BIT[i]++;
    }
    for (int qry : End[r]) {
      ans[qry] = global;
      for (int i = Left[qry]; i > 0; i -= i & -i) ans[qry] -= BIT[i];
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
