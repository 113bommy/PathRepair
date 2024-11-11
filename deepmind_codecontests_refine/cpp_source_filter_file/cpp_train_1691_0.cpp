#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
inline void quickread() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
int a[100010];
int n;
inline void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int cur = 1, last = n;
  for (int i = n; i >= 1; --i) {
    if (a[i] == cur) {
      for (int j = i + 1; j <= last; ++j) {
        if (a[i] != ++cur) {
          cout << "No\n";
          return;
        }
      }
      ++cur;
      last = i - 1;
    }
  }
  cout << "Yes\n";
}
int main() {
  quickread();
  int T;
  cin >> T;
  while (T--) {
    work();
  }
  return 0;
}
