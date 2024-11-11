#include <bits/stdc++.h>
using namespace std;
const long long mx = 105;
const long long maxn = 1000001;
const long long mod = 1000000007;
vector<vector<int>> adj;
vector<long long> nc;
vector<long long> dep, vec;
bool in[maxn];
long long res;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    long long n, i, j, k, r;
    cin >> n;
    long long a[n][n];
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 0) {
          r = i;
        }
      }
    }
    if (n == 1) {
      cout << 1 << "\n";
    } else {
      long long msum = 0;
      if (i - 1 >= 0) {
        for (j = 0; j < n; j++) {
          msum += a[i - 1][j];
        }
      } else if (i + 1 < n) {
        for (j = 0; j < n; j++) {
          msum += a[i + 1][j];
        }
      }
      long long rs = 0, c;
      for (j = 0; j < n; j++) {
        if (a[r][j] == 0) {
          c = j;
        } else {
          rs += a[r][j];
        }
      }
      a[r][c] = msum - rs;
      if (a[r][c] <= 0) {
        cout << "-1\n";
      } else {
        int flag = 1;
        for (i = 0; i < n; i++) {
          long long cs = 0;
          for (j = 0; j < n; j++) {
            cs += a[i][j];
          }
          if (cs != msum) {
            flag = 0;
            break;
          }
        }
        for (i = 0; i < n; i++) {
          long long cs = 0;
          for (j = 0; j < n; j++) {
            cs += a[j][i];
          }
          if (cs != msum) {
            flag = 0;
            break;
          }
        }
        long long cs = 0;
        for (i = 0; i < n; i++) {
          cs += a[i][i];
        }
        if (cs != msum) {
          flag = 0;
        }
        cs = 0;
        for (i = 0; i < n; i++) {
          cs += a[i][n - 1 - i];
        }
        if (cs != msum) {
          flag = 0;
        }
        if (flag) {
          cout << a[r][c] << "\n";
        } else {
          cout << "-1\n";
        }
      }
    }
  }
}
