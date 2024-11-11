#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool could[6][6];
bool could1[6][6][6];
map<long long, int> mp;
vector<long long> fuck[300];
int k, n;
void init() {
  memset(could, 0, sizeof(could));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i != j) {
        could[i][j] = 1;
      }
    }
  }
  could[0][1] = could[1][0] = 0;
  could[2][3] = could[3][2] = 0;
  could[4][5] = could[5][4] = 0;
  memset(could1, 0, sizeof(could1));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) {
        could1[i][j][k] = could[i][j] & could[i][k];
      }
    }
  }
}
char shit[100];
vector<long long> dfs(long long id, int ceng) {
  if (mp.count(id) == 0) {
    return fuck[ceng];
  }
  if (ceng == k) {
    vector<long long> now(6, 1);
    if (mp[id] != -1) {
      int c = mp[id];
      for (int i = 0; i < 6; i++) {
        if (i != c) {
          now[i] = 0;
        }
      }
    }
    return now;
  }
  vector<long long> L = dfs(id << 1, ceng + 1);
  vector<long long> R = dfs(id << 1 | 1, ceng + 1);
  vector<long long> now(6, 0);
  for (int c = 0; c < 6; c++) {
    for (int l = 0; l < 6; l++) {
      for (int r = 0; r < 6; r++) {
        now[c] = (now[c] + could1[c][l][r] * L[l] * R[r]) % mod;
      }
    }
  }
  if (mp[id] != -1) {
    int c = mp[id];
    for (int i = 0; i < 6; i++) {
      if (i != c) {
        now[i] = 0;
      }
    }
  }
  return now;
}
int main() {
  init();
  mp.clear();
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n; i++) {
    long long x;
    int c;
    scanf("%lld%s", &x, shit);
    if (shit[0] == 'w') {
      c = 0;
    } else if (shit[0] == 'y') {
      c = 1;
    } else if (shit[0] == 'g') {
      c = 2;
    } else if (shit[0] == 'b') {
      c = 3;
    } else if (shit[0] == 'r') {
      c = 4;
    } else if (shit[0] == 'o') {
      c = 5;
    } else {
      raise(1);
    }
    mp[x] = c;
    x = x >> 1;
    while (x) {
      if (mp.count(x)) break;
      mp[x] = -1;
      x = x >> 1;
    }
  }
  for (int i = 1; i <= k; i++) {
    fuck[i] = vector<long long>(6);
  }
  for (int i = 0; i < 6; i++) fuck[k][i] = 1;
  for (int i = k - 1; i; i--) {
    for (int c = 0; c < 6; c++) {
      for (int l = 0; l < 6; l++) {
        for (int r = 0; r < 6; r++) {
          fuck[i][c] =
              (fuck[i][c] + could1[c][l][r] * fuck[i + 1][l] * fuck[i + 1][r]) %
              mod;
        }
      }
    }
  }
  long long ans = 0;
  auto now = dfs(1, 1);
  for (int i = 0; i < 6; i++) {
    ans += now[i];
  }
  printf("%lld\n", ans % mod);
  return 0;
}
