#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
int n, k;
string m;
long long cnt = 0;
long long arr[3004][3004];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  n -= k;
  arr[0][0] = 1;
  for (int i = 0; i < n + 10; ++i) {
    for (int j = 0; j < n + 10; ++j) {
      arr[i + 1][j + 1] += arr[i][j];
      if (arr[i + 1][j + 1] > Mod) {
        arr[i + 1][j + 1] -= Mod;
      }
    }
    for (int j = 1; j < n + 10; ++j) {
      arr[i + 1][j - 1] += arr[i][j];
      if (arr[i + 1][j - 1] > Mod) {
        arr[i + 1][j - 1] -= Mod;
      }
    }
  }
  int Mb = 0, b = 0;
  cin >> m;
  for (int i = 0; i < m.size(); ++i) {
    if (m[i] == '(')
      ++b;
    else
      --b;
    Mb = min(Mb, b);
  }
  for (int i = 0; i < n + 1; ++i) {
    if (k == 0 && i != 0) break;
    for (int j = Mb; j < n + 10; ++j) {
      int nb = b + j;
      if (nb < 0 || nb > 3000) continue;
      cnt += arr[i][j] * arr[n - i][nb];
      cnt %= Mod;
    }
  }
  cout << cnt << endl;
}
