#include <bits/stdc++.h>
using namespace std;
const int MN = 100 + 10, MX = 300 + 30;
struct mat {
  int a[MX][MX];
  mat() {
    for (int i = 0; i < MX; i++) {
      for (int j = 0; j < MX; j++) {
        a[i][j] = 0;
      }
    }
  }
};
mat dp;
mat ndp;
mat ans1;
mat ans2;
int ar[MN];
void printmx(mat arr) {
  int mx = 0;
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < MX; j++) {
      mx = max(mx, arr.a[i][j]);
    }
  }
  cout << mx << endl;
}
void print(mat arr) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << arr.a[i][j] << " ";
    }
    cout << endl;
  }
}
mat ans(int x) {
  if (x == 1) {
    return dp;
  }
  ans1 = ans(x / 2);
  ans2 = ans1;
  for (int i = 0; i < MX; i++) {
    for (int j = i; j < MX; j++) {
      for (int k = i; k <= j; k++) {
        ans2.a[i][j] = max(ans2.a[i][j], ans1.a[i][k] + ans1.a[k][j]);
      }
    }
  }
  if (x & 1) {
    ans1 = ans2;
    for (int i = 0; i < MX; i++) {
      for (int j = i; j < MX; j++) {
        for (int k = i; k <= j; k++) {
          ans2.a[i][j] = max(ans2.a[i][j], ans1.a[i][k] + dp.a[k][j]);
        }
      }
    }
  }
  return ans2;
}
int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < n; i++) {
    ndp = dp;
    for (int j = 0; j <= ar[i]; j++) {
      for (int k = j; k <= ar[i]; k++) {
        ndp.a[j][ar[i]] = max(ndp.a[j][ar[i]], dp.a[j][k] + 1);
      }
    }
    dp = ndp;
  }
  mat ret = ans(t);
  int mx = 0;
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < MX; j++) {
      mx = max(mx, ret.a[i][j]);
    }
  }
  cout << mx;
}
