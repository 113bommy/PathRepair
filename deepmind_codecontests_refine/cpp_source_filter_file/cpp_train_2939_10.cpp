#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003, M = 1000000007;
int n, m;
int s[N];
int f[N], h[N];
vector<int> a[N];
vector<int> b[N];
int q[N];
void solv() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
    a[s[i]].push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &f[i], &h[i]);
    b[f[i]].push_back(h[i]);
  }
  for (int i = 1; i <= n; ++i) sort((b[i]).begin(), (b[i]).end());
  int ans1 = -N * 2, ans2;
  for (int m = 0; m <= n; ++m) {
    int yans1 = 0, yans2 = 1;
    for (int i = 1; i <= n; ++i) {
      while (q[i] < ((int)(a[i]).size()) && a[i][q[i]] <= m) ++q[i];
      int minu = q[i];
      int maxu = ((int)(a[i]).size()) - q[i];
      if (minu > maxu) swap(minu, maxu);
      if (((int)(b[i]).size()) <= 1 || !(b[i][0] <= minu && b[i][1] <= maxu)) {
        if (i == s[m]) {
          bool z = false;
          for (int j = 0; j < b[i].size(); ++j) {
            if (b[i][j] == q[i]) {
              z = true;
              break;
            }
          }
          if (!z) {
            yans1 = -N;
            break;
          }
          yans1++;
          continue;
        }
        int q = 0;
        for (int j = 0; j < b[i].size(); ++j) {
          if (b[i][j] <= maxu) {
            q++;
          }
          if (b[i][j] <= minu) {
            q++;
          }
        }
        if (q) {
          yans1++;
          yans2 = (yans2 * 1LL * q) % M;
        }
      } else {
        if (i == s[m]) {
          bool z = true;
          for (int j = 0; j < b[i].size(); ++j) {
            if (b[i][j] == q[i]) {
              z = true;
              break;
            }
          }
          if (!z) {
            yans1 = -N;
            break;
          }
          int qq = 0;
          for (int j = 0; j < b[i].size(); ++j) {
            if (b[i][j] == q[i]) continue;
            if (b[i][j] <= ((int)(a[i]).size()) - q[i]) {
              ++qq;
            }
          }
          if (!qq) {
            yans1 = -N;
            break;
          }
          yans1 += 2;
          yans2 = (yans2 * 1LL * qq) % M;
          continue;
        }
        int k;
        for (int j = 0; j < b[i].size(); ++j) {
          if (b[i][j] <= maxu) {
            k = j;
          }
        }
        int q = 0;
        for (int j = 0; j < b[i].size(); ++j) {
          if (b[i][j] <= minu) {
            q += (k - j);
          }
        }
        for (int j = 0; j < b[i].size(); ++j) {
          if (b[i][j] <= minu) {
            k = j;
          }
        }
        for (int j = 0; j < b[i].size(); ++j) {
          if (b[i][j] <= maxu) {
            q += max(0, (k - j));
          }
        }
        if (q) {
          yans1 += 2;
          yans2 = (yans2 * 1LL * q) % M;
        }
      }
    }
    if (yans1 > ans1) {
      ans1 = yans1;
      ans2 = yans2;
    } else if (yans1 == ans1) {
      ans2 = (yans2 + ans2) % M;
    }
  }
  printf("%d %d\n", ans1, ans2);
}
int main() {
  solv();
  return 0;
}
