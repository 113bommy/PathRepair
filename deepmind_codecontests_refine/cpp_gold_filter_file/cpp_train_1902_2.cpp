#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt[N];
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    cnt[i] = 0;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; ++i) {
      int tmp;
      cin >> tmp;
      cnt[tmp]++;
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      mx = max(mx, cnt[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] == mx) {
        ans++;
      }
    }
    cout << (n - mx * ans) / (mx - 1) + ans - 1 << '\n';
  }
  return 0;
}
