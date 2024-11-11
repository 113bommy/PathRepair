#include <bits/stdc++.h>
using namespace std;
int lsone(int n) { return (n & -n); }
void mult(long long int a[25][25], long long int b[25][25],
          long long int c[25][25], int m, int n, int p) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= p; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= n; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % 1000000007;
        c[i][j] %= 1000000007;
      }
    }
  }
}
void mat_pow(long long int a[25][25], long long int c[25][25], int n,
             long long int p) {
  if (p == 0) {
    for (int i = 1; i <= n; i++) c[i][i] = 1;
  } else if (p == 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) c[i][j] = a[i][j];
    }
  } else {
    long long int d[25][25];
    mat_pow(a, d, n, p / 2);
    if (p % 2) {
      long long int e[25][25];
      mult(d, d, e, n, n, n);
      mult(e, a, c, n, n, n);
    } else {
      mult(d, d, c, n, n, n);
    }
  }
}
long long int pow1(long long int a, long long int b) {
  if (b == 0)
    return 1ll;
  else if (b == 1)
    return a;
  else {
    long long int x = pow1(a, b / 2);
    x *= x;
    x %= 1000000007;
    if (b % 2) {
      x *= a;
      x %= 1000000007;
    }
    return x;
  }
}
int n, m, k, s, temp, dist[10][10], a[2010][2010], mdist[10], q[101000];
vector<vector<int> > mat(21000);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> temp;
      a[i][j] = temp;
      mat[(temp - 1) * m + j].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= m; j++)
      sort(mat[(i - 1) * m + j].begin(), mat[(i - 1) * m + j].end());
  }
  for (int i = 1; i <= n; i++) {
    memset(mdist, 0, sizeof(mdist));
    for (int j = 1; j <= m; j++) {
      for (int x = 1; x <= k; x++) {
        if (mdist[x] != 0) mdist[x]++;
        int minim = n, maxim = 0;
        if (mat[(x - 1) * m + j].size() > 0) {
          minim = mat[(x - 1) * m + j][0];
          maxim = mat[(x - 1) * m + j][mat[(x - 1) * m + j].size() - 1];
        }
        int dist1 = i - minim, dist2 = maxim - i;
        mdist[x] = max(mdist[x], max(dist1, dist2));
        dist[a[i][j]][x] = max(dist[a[i][j]][x], mdist[x]);
        dist[x][a[i][j]] = dist[a[i][j]][x];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(mdist, 0, sizeof(mdist));
    for (int j = m; j >= 1; j--) {
      for (int x = 1; x <= k; x++) {
        if (mdist[x] != 0) mdist[x]++;
        int minim = n, maxim = 0;
        if (mat[(x - 1) * m + j].size() > 0) {
          minim = mat[(x - 1) * m + j][0];
          maxim = mat[(x - 1) * m + j][mat[(x - 1) * m + j].size() - 1];
        }
        int dist1 = i - minim, dist2 = maxim - i;
        mdist[x] = max(mdist[x], max(dist1, dist2));
        dist[a[i][j]][x] = max(dist[a[i][j]][x], mdist[x]);
        dist[x][a[i][j]] = dist[a[i][j]][x];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= s; i++) {
    cin >> q[i];
  }
  for (int i = 2; i <= s; i++) {
    ans = max(ans, dist[q[i - 1]][q[i]]);
  }
  cout << ans << "\n";
  return 0;
}
