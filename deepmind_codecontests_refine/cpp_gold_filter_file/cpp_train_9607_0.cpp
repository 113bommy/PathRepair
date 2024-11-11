#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
char g[100][100];
int kk[10000][6];
int k;
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};
void c3(int i, int j) {
  vector<pair<int, pair<int, int>>> v;
  for (int p = 0; p < 4; p++) {
    v.push_back(make_pair(g[i + dx[p]][j + dy[p]] - '0',
                          make_pair(i + dx[p], j + dy[p])));
  }
  sort(v.begin(), v.end());
  for (int p = 0; p < 3; p++) {
    kk[k][p + p] = v[p + 1].second.first;
    kk[k][p + p + 1] = v[p + 1].second.second;
  }
  k++;
}
void c2(int i, int j) {
  vector<pair<int, pair<int, int>>> v;
  for (int p = 0; p < 4; p++) {
    v.push_back(make_pair(g[i + dx[p]][j + dy[p]] - '0',
                          make_pair(i + dx[p], j + dy[p])));
  }
  sort(v.rbegin(), v.rend());
  for (int p = 0; p < 3; p++) {
    kk[k][p + p] = v[p + 1].second.first;
    kk[k][p + p + 1] = v[p + 1].second.second;
  }
  k++;
  for (int p = 0; p < 3; p++) {
    if (!p) {
      kk[k][p + p] = v[p].second.first;
      kk[k][p + p + 1] = v[p].second.second;
    } else {
      kk[k][p + p] = v[p + 1].second.first;
      kk[k][p + p + 1] = v[p + 1].second.second;
    }
  }
  k++;
}
void c1(int i, int j) {
  vector<pair<int, pair<int, int>>> v;
  for (int p = 0; p < 4; p++) {
    v.push_back(make_pair(g[i + dx[p]][j + dy[p]] - '0',
                          make_pair(i + dx[p], j + dy[p])));
  }
  sort(v.begin(), v.end());
  for (int p = 0; p < 3; p++) {
    kk[k][p + p] = v[p + 1].second.first;
    kk[k][p + p + 1] = v[p + 1].second.second;
  }
  k++;
  for (int p = 0; p < 3; p++) {
    if (p < 2) {
      kk[k][p + p] = v[p].second.first;
      kk[k][p + p + 1] = v[p].second.second;
    } else {
      kk[k][p + p] = v[p + 1].second.first;
      kk[k][p + p + 1] = v[p + 1].second.second;
    }
  }
  k++;
  for (int p = 0; p < 3; p++) {
    if (!p) {
      kk[k][p + p] = v[p].second.first;
      kk[k][p + p + 1] = v[p].second.second;
    } else {
      kk[k][p + p] = v[p + 1].second.first;
      kk[k][p + p + 1] = v[p + 1].second.second;
    }
  }
  k++;
}
void c4(int i, int j) {
  vector<pair<int, pair<int, int>>> v;
  for (int p = 0; p < 4; p++) {
    v.push_back(make_pair(g[i + dx[p]][j + dy[p]] - '0',
                          make_pair(i + dx[p], j + dy[p])));
  }
  for (int p = 0; p < 3; p++) {
    kk[k][p + p] = v[p].second.first;
    kk[k][p + p + 1] = v[p].second.second;
  }
  k++;
  for (int p = 0; p < 3; p++) {
    kk[k][p + p] = v[p + 1].second.first;
    kk[k][p + p + 1] = v[p + 1].second.second;
  }
  k++;
  for (int p = 0; p < 3; p++) {
    if (p < 2) {
      kk[k][p + p] = v[p].second.first;
      kk[k][p + p + 1] = v[p].second.second;
    } else {
      kk[k][p + p] = v[p + 1].second.first;
      kk[k][p + p + 1] = v[p + 1].second.second;
    }
  }
  k++;
  for (int p = 0; p < 3; p++) {
    if (!p) {
      kk[k][p + p] = v[p].second.first;
      kk[k][p + p + 1] = v[p].second.second;
    } else {
      kk[k][p + p] = v[p + 1].second.first;
      kk[k][p + p + 1] = v[p + 1].second.second;
    }
  }
  k++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  for (long long tc = 1; tc <= T; tc++) {
    int n, m;
    cin >> n >> m;
    k = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    if (n % 2 + m % 2) {
      if (n % 2) {
        for (int i = 1; i < m; i++) {
          if (g[n - 1][i - 1] == '0' && g[n - 1][i] == '1') {
            kk[k][0] = n - 1;
            g[n - 1][i] = '0';
            kk[k][1] = i;
            kk[k][2] = n - 2;
            g[n - 2][i] = '1' - g[n - 2][i] + '0';
            kk[k][3] = i;
            kk[k][4] = n - 2;
            g[n - 2][i - 1] = '1' - g[n - 2][i - 1] + '0';
            kk[k][5] = i - 1;
            k++;
          } else if (g[n - 1][i - 1] == '1' && g[n - 1][i] == '0') {
            kk[k][0] = n - 1;
            g[n - 1][i - 1] = '0';
            kk[k][1] = i - 1;
            kk[k][2] = n - 2;
            g[n - 2][i] = '1' - g[n - 2][i] + '0';
            kk[k][3] = i;
            kk[k][4] = n - 2;
            g[n - 2][i - 1] = '1' - g[n - 2][i - 1] + '0';
            kk[k][5] = i - 1;
            k++;
          } else if (g[n - 1][i - 1] == '1' && g[n - 1][i] == '1') {
            kk[k][0] = n - 1;
            g[n - 1][i - 1] = '0';
            kk[k][1] = i - 1;
            kk[k][2] = n - 1;
            g[n - 1][i] = '0';
            kk[k][3] = i;
            kk[k][4] = n - 2;
            kk[k][5] = i - 1;
            g[n - 2][i - 1] = '1' - g[n - 2][i - 1] + '0';
            k++;
          }
        }
      }
      if (m % 2) {
        for (int i = 1; i < n; i++) {
          if (g[i - 1][m - 1] == '0' && g[i][m - 1] == '1') {
            kk[k][0] = i;
            g[i][m - 1] = '0';
            kk[k][1] = m - 1;
            kk[k][2] = i;
            g[i][m - 2] = '1' - g[i][m - 2] + '0';
            kk[k][3] = m - 2;
            kk[k][4] = i - 1;
            g[i - 1][m - 2] = '1' - g[i - 1][m - 2] + '0';
            kk[k][5] = m - 2;
            k++;
          } else if (g[i - 1][m - 1] == '1' && g[i][m - 1] == '0') {
            kk[k][0] = i - 1;
            g[i - 1][m - 1] = '0';
            kk[k][1] = m - 1;
            kk[k][2] = i;
            g[i][m - 2] = '1' - g[i][m - 2] + '0';
            kk[k][3] = m - 2;
            kk[k][4] = i - 1;
            g[i - 1][m - 2] = '1' - g[i - 1][m - 2] + '0';
            kk[k][5] = m - 2;
            k++;
          } else if (g[i - 1][m - 1] == '1' && g[i][m - 1] == '1') {
            kk[k][0] = i - 1;
            g[i - 1][m - 1] = '0';
            kk[k][1] = m - 1;
            kk[k][2] = i;
            g[i][m - 1] = '0';
            kk[k][3] = m - 1;
            kk[k][4] = i - 1;
            g[i - 1][m - 2] = '1' - g[i - 1][m - 2] + '0';
            kk[k][5] = m - 2;
            k++;
          }
        }
      }
    }
    for (int i = 0; i < n - 1; i += 2) {
      for (int j = 0; j < m - 1; j += 2) {
        int count = g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1] -
                    '0' - '0' - '0' - '0';
        if (count == 3) {
          c3(i, j);
        } else if (count == 2) {
          c2(i, j);
        } else if (count == 1) {
          c1(i, j);
        } else if (count == 4) {
          c4(i, j);
        }
      }
    }
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 6; j++) {
        cout << kk[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
