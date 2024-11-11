#include <bits/stdc++.h>
using namespace std;
const int N = 607;
int n;
bool z[N][N], used[N][N];
int l[N], r[N];
bool calcZ(int i, int j) {
  if (i > j) return true;
  if (used[i][j]) return z[i][j];
  used[i][j] = true;
  for (int cnt = 0; cnt < (int)(j - i + 1); ++cnt)
    if ((2 * cnt + 1 >= l[i] && 2 * cnt + 1 <= r[i]) && calcZ(i + 1, i + cnt) &&
        calcZ(i + cnt + 1, j))
      return z[i][j] = true;
  return z[i][j] = false;
}
void getAns(int i, int j) {
  if (l > r) return;
  for (int cnt = 0; cnt < (int)(j - i + 1); ++cnt)
    if ((2 * cnt + 1 >= l[i] && 2 * cnt + 1 <= r[i]) && calcZ(i + 1, i + cnt) &&
        calcZ(i + cnt + 1, j)) {
      cout << '(';
      getAns(i + 1, i + cnt);
      cout << ')';
      getAns(i + cnt + 1, j);
      return;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), f(5, 0);
  for (int i = 0; i < (int)(n); ++i) cin >> a[i], f[a[i]]++;
  long long ans = 0;
  {
    int t = min(f[2], f[1]);
    f[3] += t, ans += t;
    f[2] -= t, f[1] -= t;
  }
  {
    if (f[1]) f[3] += f[1] / 3, ans += f[1] / 3 * 3 - f[1] / 3, f[1] %= 3;
    if (f[2]) f[3] += 2 * (f[2] / 3), ans += 2 * (f[2] / 3), f[2] %= 3;
  }
  {
    if (f[1]) {
      if (f[3] >= f[1]) {
        f[4] += f[1];
        ans += f[1];
        f[1] = 0;
      } else {
        if (f[1] == 2) {
          if (f[4] == 0 && f[3] < 2) {
            cout << -1 << endl;
            return 0;
          }
          ans += 2;
        } else {
          if (f[3] >= 1)
            ans += 1;
          else {
            if (f[4] < 2) {
              cout << -1 << endl;
              return 0;
            }
            ans += 2;
          }
        }
      }
    }
    if (f[2]) {
      if (f[4] >= f[2]) {
        ans += f[2];
      } else {
        if (f[2] == 2) {
          ans += 2;
        } else {
          if (f[4] > 0)
            ans++;
          else if (f[3] >= 2)
            ans += 3;
          else {
            cout << -1 << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
