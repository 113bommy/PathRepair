#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 40 + 1;
int n, m, arr[N], hi, lo;
string str[5210];
map<char, string> _std;
vector<int> find_divisor(int x) {
  vector<int> ret;
  for (int i = 1; i * i <= x; i++) {
    if (x == i * (x / i)) {
      ret.push_back(i);
      if (i != x / i) ret.push_back(x / i);
    }
  }
  sort(ret.begin(), ret.end());
  reverse(ret.begin(), ret.end());
  return ret;
}
bool is_possible(int val) {
  bool ret = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + val <= n; j += val) {
      for (int k = j + 1; k < j + val; k++)
        if (str[i][k] != str[i][j]) return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + val <= n; j += val) {
      for (int k = j + 1; k < j + val; k++)
        if (str[k][i] != str[j][i]) return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst;
  cin >> tst;
  while (tst--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int first_zero = -1;
    int i;
    for (i = n - 1; i >= 0; i--) {
      if (str[i] == '0') {
        if (2 * (i + 1) > n) {
          cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
          break;
        } else {
          cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
          break;
        }
      }
    }
    if (i < 0) {
      if (n & 1) {
        cout << 2 << ' ' << n << ' ' << (n + 1) / 2 + 1 << ' ' << n << '\n';
      } else {
        cout << 1 << ' ' << n << ' ' << n / 2 + 1 << ' ' << n << '\n';
      }
    }
  }
}
