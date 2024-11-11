#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
const int N = 1010;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int temp;
  cin >> temp;
  while (temp--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = n / 2;
    if (s.find('0') == -1) {
      cout << 1 << ' ' << num << ' ' << 2 << ' ' << num + 1 << '\n';
    } else {
      long long pos = s.find('0', 0) + 1;
      if (pos == num) {
        int ppp = s.find('0', pos);
        if (ppp == -1 and num != 1)
          cout << 1 << ' ' << num << ' ' << num << ' ' << num + num - 1 << '\n';
        else if (ppp == -1 and num == 1)
          cout << 1 << ' ' << n << ' ' << 2 << ' ' << n << '\n';
        else {
          ppp++;
          cout << 1 << ' ' << ppp << ' ' << 1 << ' ' << ppp - 1 << '\n';
        }
      } else if (pos > num) {
        cout << 1 << ' ' << pos << ' ' << 1 << ' ' << pos - 1 << '\n';
      } else if (pos < num) {
        cout << pos << ' ' << n << ' ' << pos + 1 << ' ' << n << '\n';
      }
    }
  }
  return 0;
}
