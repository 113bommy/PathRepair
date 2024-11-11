#include <bits/stdc++.h>
using namespace std;
template <class... Args>
void debug(Args... args) {
  auto tmp = {(cout << args << ' ', 0)...};
  cout << endl;
}
using ll = long long;
const int N = 2e4 + 10;
const int mod = 4933;
const double eps = 1e-9;
char a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cin >> (a + 1);
    bool flg = true;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == '0') {
        if (i - 1 > n - i - 1) {
          cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << endl;
        } else {
          cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << endl;
        }
        flg = false;
        break;
      }
    }
    if (flg) {
      cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
    }
  }
}
