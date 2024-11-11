#include <bits/stdc++.h>
using namespace std;
const int N = 19;
int n;
int B[N + 3][N + 3];
long long f[N][(1 << N) + 11];
int bit[(1 << N) + 11];
long long g[N][(1 << N) + 11], ans[(1 << N) + 11], tmp[(1 << N) + 11];
map<int, int> mp;
vector<int> a;
void FMT_OR(long long *x, int fl) {
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 1 << n; s++) {
      if (s >> i & 1) {
        x[s] += fl * x[s ^ (1 << i)];
      }
    }
  }
}
void FMT_AND(long long *x, int fl) {
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 1 << n; s++) {
      if (!(s >> i & 1)) {
        x[s] += fl * x[s ^ (1 << i)];
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%1d", &B[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) f[i][1 << i - 1] = 1;
  for (int i = 0; i < 1 << n; i++) {
    bit[i] = bit[i >> 1] + (i & 1);
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        int s = i ^ (1 << j);
        for (int k = 0; k < n; k++) {
          if ((s >> k & 1) && B[k + 1][j + 1]) f[j + 1][i] += f[k + 1][s];
        }
      }
      g[bit[i]][i] += f[j + 1][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    FMT_OR(g[i], 1);
  }
  for (int i = 0; i < 1 << n - 1; i++) {
    a.clear();
    int las = 1;
    for (int j = 0; j < n - 1; j++) {
      if (i >> j & 1) {
        las++;
      } else {
        a.push_back(las);
        las = 1;
      }
    }
    a.push_back(las);
    sort(a.begin(), a.end());
    int ha = 0, s = a.size();
    for (int j = 0; j < s; j++) {
      ha = ha * 233 + a[j];
    }
    if (mp[ha]) {
      ans[i] = ans[mp[ha]];
      continue;
    }
    mp[ha] = i;
    for (int j = 0; j < 1 << n; j++) tmp[j] = 1;
    for (int j = 0; j < s; j++) {
      for (int k = 0; k < 1 << n; k++) {
        tmp[k] = tmp[k] * g[a[j]][k];
      }
    }
    FMT_OR(tmp, -1);
    ans[i] = tmp[(1 << n) - 1];
  }
  FMT_AND(ans, -1);
  for (int s = 0; s < 1 << (n - 1); s++) {
    printf("%d ", ans[s]);
  }
  puts("");
  return 0;
}
