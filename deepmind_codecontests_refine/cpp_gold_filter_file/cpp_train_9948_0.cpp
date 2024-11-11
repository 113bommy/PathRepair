#include <bits/stdc++.h>
const int N = 1e6 + 100;
int n, m;
std::vector<int> f[N];
std::vector<int> vec[N];
int cntTeam;
void init() {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) {
      std::swap(u, v);
    }
    f[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    while (t--) {
      int l;
      scanf("%d", &l);
      vec[i].push_back(l);
      cntTeam = std::max(cntTeam, l);
    }
  }
}
void getRand(int belong[]) {
  for (int i = 1; i <= cntTeam; i++) {
    belong[i] = rand() % 2;
  }
}
void work() {
  static int belong[N];
  while (true) {
    getRand(belong);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      int cnt[2] = {0, 0};
      for (int j = 0; j < (int)vec[i].size(); j++) {
        cnt[belong[vec[i][j]]]++;
      }
      if (!(cnt[0] > 0 && cnt[1] > 0)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  static int g[N][2];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)vec[i].size(); j++) {
      g[i][belong[vec[i][j]]] = vec[i][j];
    }
  }
  static int state[N];
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < (int)f[i].size(); j++) {
      cnt += (state[f[i][j]] == 1);
    }
    if (cnt > (int)f[i].size() - cnt) {
      state[i] = 0;
    } else {
      state[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", g[i][state[i]], " \n"[i == n]);
  }
  for (int i = 1; i <= cntTeam; i++) {
    printf("%d%c", belong[i] + 1, " \n"[i == cntTeam]);
  }
}
int main() {
  init();
  work();
  return 0;
}
