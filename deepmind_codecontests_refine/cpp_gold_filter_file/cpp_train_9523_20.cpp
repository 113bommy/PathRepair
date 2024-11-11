#include <bits/stdc++.h>
using namespace std;
int ans[101];
vector<int> t;
vector<vector<int> > data;
int main() {
  long long n, m;
  cin >> n >> m;
  int L = 0, R = n - 1;
  for (int i = 0; i + 1 < n; ++i) {
    long long cur = 1ll << (n - i - 2);
    if (m <= cur) {
      ans[L] = i + 1;
      ++L;
    } else {
      m -= cur;
      ans[R] = i + 1;
      --R;
    }
  }
  ans[R] = n;
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
  return 0;
}
