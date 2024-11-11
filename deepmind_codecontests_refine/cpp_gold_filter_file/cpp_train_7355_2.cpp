#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const long long ll_inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  int n, a, b, cnt = 0;
  string str;
  cin >> n >> a >> b;
  cin >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] == '.') {
      if (a > b) {
        if (i == 0 && a > 0) {
          str[i] = 'A';
          cnt++;
          a--;
          continue;
        }
        if (str[i - 1] != 'A' && a > 0) {
          str[i] = 'A';
          cnt++;
          a--;
        } else {
          if (b > 0) {
            str[i] = 'B';
            cnt++;
            b--;
          }
        }
      } else {
        if (i == 0 && b > 0) {
          str[i] = 'B';
          cnt++;
          b--;
          continue;
        }
        if (str[i - 1] != 'B' && b > 0) {
          str[i] = 'B';
          cnt++;
          b--;
        } else {
          if (a > 0) {
            str[i] = 'A';
            cnt++;
            a--;
          }
        }
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
