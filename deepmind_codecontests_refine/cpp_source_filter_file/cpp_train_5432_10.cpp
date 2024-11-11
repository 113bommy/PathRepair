#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, MAXN = 1e5;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int n;
string w;
bool ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  cout.flush();
  bool ans;
  cin >> ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, -1));
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  int ans;
  for (int i = 0; i < n; ++i) {
    for (int j = (i % 2); j < n - 2; j += 2) {
      ans = ask(i + 1, j + 1, i + 1, j + 3);
      if (ans)
        a[i][j + 2] = a[i][j];
      else
        a[i][j + 2] = !a[i][j];
    }
    if (i % 2 == 0) {
      if (i + 1 < n) {
        ans = ask(i + 1, 1, i + 2, 2);
        if (ans)
          a[i + 1][1] = a[i][0];
        else
          a[i + 1][1] = !a[i][0];
      }
      if (i + 2 < n) {
        ans = ask(i + 1, 1, i + 3, 1);
        if (ans)
          a[i + 2][0] = a[i][0];
        else
          a[i + 2][0] = !a[i][0];
      }
    }
  }
  a[0][1] = 2;
  for (int i = 1; i < n - 2; i += 2) {
    ans = ask(1, i + 1, 1, i + 3);
    if (ans)
      a[0][i + 2] = a[0][i];
    else
      a[0][i + 2] = -a[0][i];
  }
  ans = ask(1, 2, 2, 3);
  if (ans)
    a[1][2] = a[0][1];
  else
    a[1][2] = -a[0][1];
  ans = ask(2, 1, 2, 3);
  if (ans)
    a[1][0] = a[1][2];
  else
    a[1][0] = -a[1][2];
  for (int i = 1; i < n; ++i) {
    for (int j = !(i % 2); j < n - 2; j += 2) {
      if (i == 1 && j == 0) continue;
      ans = ask(i + 1, j + 1, i + 1, j + 3);
      if (ans)
        a[i][j + 2] = a[i][j];
      else
        a[i][j + 2] = -a[i][j];
    }
    if (i % 2) {
      if (i + 1 < n) {
        ans = ask(i + 1, 1, i + 2, 2);
        if (ans)
          a[i + 1][1] = a[i][0];
        else
          a[i + 1][1] = -a[i][0];
      }
      if (i + 2 < n) {
        ans = ask(i + 1, 1, i + 3, 1);
        if (ans)
          a[i + 2][0] = a[i][0];
        else
          a[i + 2][0] = -a[i][0];
      }
    }
  }
  int t = 1;
  int i = 0;
  for (; i < 2 * n - 4; ++i) {
    if ((a[max(0, i - n + 1)][min(i, n - 1)] ==
         a[max(0, i - n + 3)][min(i + 2, n - 1)]) !=
        (a[max(0, i - n + 2)][min(i + 1, n - 1)] ==
         a[max(0, i - n + 4)][min(i + 3, n - 1)]))
      break;
  }
  int x1 = max(0, i - n + 1), y1 = min(i, n - 1), x2 = max(0, i - n + 4),
      y2 = min(i + 3, n - 1);
  ans = ask(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
  if (ans) {
    if ((x1 + y1) % 2) {
      t = a[x2][y2];
      if (a[x1][y1] != 2) t = !t;
    } else {
      t = a[x1][y1];
      if (a[x2][y2] != 2) t = !t;
    }
  } else {
    if ((x1 + y1) % 2) {
      t = a[x2][y2];
      if (a[x1][y1] == 2) t = !t;
    } else {
      t = a[x1][y1];
      if (a[x2][y2] == 2) t = !t;
    }
  }
  cout << '!' << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 2) {
        a[i][j] = t;
      }
      if (a[i][j] == -2) a[i][j] = !t;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
