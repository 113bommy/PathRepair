#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, m;
int l[17];
int r[17];
long long func(int i, int d, int res) {
  if (l[i + 1] == -1) {
    if (d == 0) {
      return r[i] + res;
    } else {
      return (m + 1 - l[i]) + res;
    }
  }
  if (d == 0) {
    return min(func(i + 1, 0, 2 * r[i] + res + 1),
               func(i + 1, 1, m + 1 + res + 1));
  } else {
    if (l[i] == 0) {
      return min(func(i + 1, 1, res + 1), func(i + 1, 0, m + 1 + res + 1));
    }
    return min(func(i + 1, 1, 2 * (m + 1 - l[i]) + res + 1),
               func(i + 1, 0, m + 1 + res + 1));
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int a[n][m + 2];
  int x;
  for (int i = 0; i < n; i++) {
    i = n - i - 1;
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '0') {
        continue;
      }
      if (l[i] == 0) {
        l[i] = j;
        r[i] = j;
      } else {
        r[i] = j;
      }
    }
    i = n - i - 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (l[i] == 0) {
      l[i] = -1;
    } else {
      break;
    }
  }
  l[n] = -1;
  if (l[0] == -1) {
    cout << 0 << endl;
    return 0;
  }
  cout << func(0, 0, 0) << endl;
}
