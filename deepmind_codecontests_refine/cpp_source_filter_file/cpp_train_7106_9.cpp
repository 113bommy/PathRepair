#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
int a[maxn], b[maxn];
int arr[maxn][maxn];
int n, m;
bool check(int a) {
  int flag = 1;
  for (int i = (1); i <= (n); ++i) {
    int f = 0;
    for (int j = (1); j <= (m); ++j) {
      if ((arr[i][j] | a) == a) f = 1;
    }
    if (f == 0) {
      flag = 0;
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> m) {
    for (int i = (1); i <= (n); ++i) cin >> a[i];
    for (int i = (1); i <= (m); ++i) cin >> b[i];
    for (int i = (1); i <= (n); ++i) {
      for (int j = (1); j <= (m); ++j) {
        arr[i][j] = a[i] & b[j];
      }
    }
    int minn = 1 << 9 - 1;
    for (int ans = (1 << 9 - 1); ans >= (0); --ans) {
      if (check(ans)) minn = min(ans, minn);
    }
    cout << minn << endl;
  }
  return 0;
}
