#include <bits/stdc++.h>
using namespace std;
int n;
int a[5011];
int ans[5011];
int b1[5011][2];
int b2[5011][2];
bool cover[5011][2];
int f[10011];
int g[10011];
int ans0;
int main() {
  int i, j, k;
  int t = 0;
  int x0;
  cin >> n;
  if (n % 2 == 1) {
    for (i = 0; i < n; i++) {
      cout << "? " << 0 << " " << i << endl;
      fflush(stdout);
      cin >> a[i];
      t ^= a[i];
    }
    for (i = 0; i < n; i++) {
      t ^= i;
    }
    x0 = t;
    for (i = 0; i < n; i++) {
      ans[x0 ^ a[i]] = i;
    }
    cout << "!" << endl;
    cout << 1 << endl;
    for (i = 0; i < n - 1; i++) {
      cout << ans[i] << ' ';
    }
    cout << ans[i] << endl;
  } else {
    ans0 = 0;
    for (i = 0; i < n - 1; i++) {
      cout << "? " << i << " " << i + 1 << endl;
      fflush(stdout);
      cin >> b1[i][0];
      b2[i + 1][1] = b1[i][0];
    }
    for (i = 0; i < n - 1; i++) {
      cout << "? " << i + 1 << " " << i << endl;
      fflush(stdout);
      cin >> b1[i + 1][1];
      b2[i][0] = b1[i + 1][1];
    }
    cout << "? " << 0 << " " << 0 << endl;
    fflush(stdout);
    cin >> b1[0][1];
    b2[0][1] = b1[0][1];
    cout << "? " << n - 1 << " " << n - 1 << endl;
    fflush(stdout);
    cin >> b1[n - 1][0];
    b2[n - 1][0] = b1[n - 1][0];
    int u = 0;
    for (i = 0; i < n; i++) {
      if (i % 2 == 0) {
        f[++u] = b1[i][0];
      } else {
        f[++u] = b2[i][0];
      }
    }
    for (i = n - 1; i >= 0; i--) {
      if (i % 2 == 1) {
        f[++u] = b1[i][1];
      } else {
        f[++u] = b2[i][1];
      }
    }
    bool ok;
    for (i = 0; i < n; i++) {
      int tmp = i;
      ok = 1;
      for (j = 1; j <= 2 * n; j++) {
        g[j] = tmp;
        tmp ^= f[j];
      }
      memset(cover, 0, sizeof(cover));
      for (j = 1; j <= 2 * n; j += 2) {
        if (g[j] < 0 || g[j] >= n) break;
        if (cover[g[j]][0] == 0) {
          cover[g[j]][0] = 1;
        } else {
          break;
        }
      }
      if (j <= 2 * n) {
        ok = 0;
        continue;
      }
      for (j = 2; j <= 2 * n; j += 2) {
        if (g[j] < 0 || g[j] >= n) break;
        if (cover[g[j]][1] == 0) {
          cover[g[j]][1] = 1;
        } else {
          break;
        }
      }
      if (j <= 2 * n) {
        ok = 0;
        continue;
      }
      int num = 1;
      int dir = 1;
      for (j = 2; j <= 2 * n; j += 2) {
        int pos = g[j];
        int id;
        if (g[j] % 2 == 0) {
          id = 1 + g[j];
        } else {
          id = 2 * n - 1 - (g[j] - 1);
        }
        if (g[id] != num) {
          break;
        }
        if (num != n - 1) {
          num += dir * 2;
        } else {
          num--;
          dir = -1;
        }
      }
      if (j <= 2 * n) {
        continue;
      }
      if (ok == 1) {
        if (ans0 == 0) {
          for (j = 1; j <= n; j += 2) {
            ans[j - 1] = g[j];
          }
          int pp = n - 1;
          for (j = n + 1; j <= 2 * n; j += 2) {
            ans[pp] = g[j];
            pp -= 2;
          }
        }
        ans0++;
      }
    }
    cout << "!" << endl;
    cout << ans0 << endl;
    for (i = 0; i < n - 1; i++) {
      cout << ans[i] << ' ';
    }
    cout << ans[i] << endl;
  }
  fflush(stdout);
  return 0;
}
