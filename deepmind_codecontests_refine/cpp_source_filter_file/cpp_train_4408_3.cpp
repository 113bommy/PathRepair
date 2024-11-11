#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[N], pri[N], tot;
vector<int> vv[20];
void init() {
  memset(vis, 0, sizeof(vis));
  vis[0] = vis[1] = 1;
  for (int i = 2; i < N; i++) {
    if (i * i >= N) break;
    if (!vis[i]) {
      for (int j = i * i; j < N; j += i) {
        vis[j] = 1;
      }
    }
  }
  tot = 0;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pri[tot++] = i;
    }
  }
  for (int i = 2; i < N; i++) {
    if (vis[i] == 0) {
      vv[i / 10000].push_back(i);
    }
  }
}
int f4(int a, int b, int c) {
  a *= 1000;
  b *= 1000;
  c *= 1000;
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (vis[a + i * 100 + j * 10 + k] == 1) continue;
        for (int i1 = 0; i1 < 10; i1++) {
          for (int j1 = 0; j1 < 10; j1++) {
            if (vis[b + j * 100 + i1 * 10 + j1] == 1) continue;
            for (int k1 = 0; k1 < 10; k1++) {
              if (vis[c + k * 100 + j1 * 10 + k1] == 1)
                continue;
              else
                cnt++;
            }
          }
        }
      }
    }
  }
  return cnt;
}
int f3(int a, int b) {
  a *= 100;
  b *= 100;
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (vis[a + i * 10 + j] == 1) continue;
      for (int i1 = 0; i1 < 10; i1++) {
        if (vis[b + j * 10 + i1] == 1)
          continue;
        else
          cnt++;
      }
    }
  }
  return cnt;
}
int f2(int a) {
  a *= 10;
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (vis[a + i] == 1)
      continue;
    else
      cnt++;
  }
  return cnt;
}
int main() {
  int T;
  scanf("%d", &T);
  init();
  while (T--) {
    int a;
    scanf("%d", &a);
    int b = a;
    int cnt = 0;
    while (b) {
      b /= 10;
      cnt++;
    }
    int x, y, z, c, d;
    if (cnt == 1) {
      printf("1\n");
      continue;
    }
    if (cnt == 2) {
      printf("%d\n", f2(a % 10));
      continue;
    }
    if (cnt == 3) {
      y = a % 10;
      a /= 10;
      x = a % 10;
      printf("%d\n", f3(x, y));
      continue;
    }
    if (cnt == 4) {
      z = a % 10;
      a /= 10;
      y = a % 10;
      a /= 10;
      x = a % 10;
      printf("%d\n", f4(x, y, z));
      continue;
    }
    if (cnt == 5) {
      z = a % 10;
      a /= 10;
      y = a % 10;
      a /= 10;
      x = a % 10;
      a /= 10;
      c = a % 10;
      int ed = vv[c].size();
      int cnt = 0;
      for (int i = 0; i < ed; i++) {
        int u = vv[c][i];
        int x1, y1, z1;
        z1 = u % 10;
        u /= 10;
        y1 = u % 10;
        u /= 10;
        z1 = u % 10;
        cnt += f4(x * 10 + x1, y * 10 + y1, z * 10 + z1);
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
