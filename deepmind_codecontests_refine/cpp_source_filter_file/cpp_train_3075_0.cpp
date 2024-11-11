#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int n, s[5010][3], sz, q[110];
vector<int> v[5010];
int g[] = {500, 1000, 1500, 2000, 2500, 3000};
pair<int, int> check(int a) {
  if (a == 5) return make_pair(0, n / 32);
  a = 1 << (a + 1);
  int first = n / a, second = 2 * n / a;
  if (first * a <= n) first++;
  return make_pair(first, second);
}
int cal(int t, int s) {
  if (t == 0) return 0;
  return s * ((250 - t) / 250.);
}
int dp[92][92][92], f[92][92][92];
int main() {
  int T, ca = 0, i, j, k, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) scanf("%d", &s[i][j]);
  }
  int w1[3] = {0}, w2[3] = {0}, w[3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++)
      if (s[j][i] > 0)
        w2[i]++;
      else if (s[j][i] < 0)
        w1[i]++;
  }
  if (w2[0] + w2[1] + w2[2] >= 90) {
    puts("1");
    return 0;
  }
  int ok = 0;
  int ans = n;
  for (int a = 0; a < 6; a++) {
    if (ok) break;
    int ka = w1[0] + w2[0];
    w[0] = g[a];
    pair<int, int> e1 = check(a);
    if (ka < e1.first || w2[0] > e1.second) continue;
    int na = min(w1[0], ka - e1.first);
    if (na >= 90) {
      ok = 1;
      break;
    }
    for (int b = 0; b < 6; b++) {
      if (ok) break;
      int kb = w1[1] + w2[1];
      w[1] = g[b];
      pair<int, int> e2 = check(b);
      if (kb < e2.first || w2[1] > e2.second) continue;
      int nb = min(w1[1], kb - e2.first);
      if (na + nb >= 90) {
        ok = 1;
        break;
      }
      for (int c = 0; c < 6; c++) {
        int kc = w1[2] + w2[2];
        w[2] = g[c];
        pair<int, int> e3 = check(c);
        if (kc < e3.first || w2[2] > e3.second) continue;
        int nc = min(w1[2], kc - e3.first);
        if (na + nb + nc >= 90) {
          ok = 1;
          break;
        }
        int lim, tot = 0, tt = 0;
        sz = 0;
        for (int i = 0; i < n; i++) {
          int sum = 0;
          for (int j = 0; j < 3; j++) {
            sum += cal(abs(s[i][j]), w[j]);
          }
          if (i == 0)
            lim = sum + (na + nb + nc) * 100;
          else if (sum > lim) {
            tot++;
            if (sz <= 90) {
              v[i].clear();
              for (int j = 1; j < 1 << 3; j++) {
                int bad = 0;
                sum = 0;
                for (int k = 0; k < 3; k++)
                  if (j >> k & 1) {
                    if (s[i][k] >= 0) {
                      bad = 1;
                      break;
                    }
                  } else
                    sum += cal(abs(s[i][k]), w[k]);
                if (!bad && sum <= lim) {
                  v[i].push_back(j);
                }
              }
              if ((int)(v[i].size())) {
                q[sz++] = i;
              }
            }
          }
        }
        for (int i = 0; i < na + 2; i++)
          for (int j = 0; j < nb + 2; j++)
            for (int k = 0; k < nc + 2; k++) dp[i][j][k] = f[i][j][k] = -1;
        dp[0][0][0] = f[0][0][0] = 0;
        int res = 0;
        for (int i = 0; i < sz; i++) {
          for (int first = 0; first < na + 1; first++) {
            if (first > i) break;
            for (int second = 0; second < nb + 1; second++) {
              if (second > i) break;
              for (int z = 0; z < nc + 1; z++)
                if (dp[first][second][z] != -1) {
                  if (z > i) break;
                  for (__typeof(v[q[i]].begin()) it = v[q[i]].begin();
                       it != v[q[i]].end(); it++) {
                    int nx = first + (*it & 1);
                    int ny = second + (*it >> 1 & 1);
                    int nz = z + (*it >> 2 & 1);
                    Max(f[nx][ny][nz], dp[first][second][z] + 1);
                    if (nx <= na && ny <= nb && nz <= nc)
                      Max(res, f[nx][ny][nz]);
                  }
                }
            }
          }
          for (int first = 0; first < na + 1; first++)
            for (int second = 0; second < nb + 1; second++)
              for (int z = 0; z < nc + 1; z++)
                dp[first][second][z] = f[first][second][z];
        }
        Min(ans, tot - res + 1);
        if (ans == 1) ok = 1;
      }
    }
  }
  if (ok) {
    puts("1");
    return 0;
  }
  printf("%d\n", ans);
  return 0;
}
