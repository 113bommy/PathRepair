#include <bits/stdc++.h>
using namespace std;
struct Triple {
  int v, d, p;
};
bool b[40004];
int main() {
  int n;
  cin >> n;
  Triple arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i].v >> arr[i].d >> arr[i].p;
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (!b[i]) {
      ++ans;
      long long tot = arr[i].v;
      int cnt = 0;
      for (int j = i + 1; j < n; ++j)
        if (!b[j]) {
          if (arr[j].p < tot) {
            b[j] = 1;
            tot += arr[j].d;
          }
          arr[j].p -= tot;
          tot -= (cnt <= arr[i].v);
          ++cnt;
        }
    }
  cout << ans << endl;
  for (int i = 0; i < n; ++i)
    if (!b[i]) cout << i + 1 << ' ';
}
