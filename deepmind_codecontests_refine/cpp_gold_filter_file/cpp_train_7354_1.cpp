#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1e5);
const long long LINF = (long long)(1e18);
const long long MX = 100500;
const double EPS = 1e-9;
const int MOD = 1000000007;
const int ROOT = 700;
const int PRM_ROOT = 5;
const int MAXN = 3000300;
struct state {
  int val;
  pair<int, int> par;
  state(int val, pair<int, int> par) : val(val), par(par) {}
  state() {}
};
int n, m[2], t;
int x[2][MAXN], posc[2][MAXN];
vector<int> coords;
int ptr[MAXN][2];
state dp[2][MAXN];
vector<int> trans;
vector<pair<int, int> > shots;
bool can;
void init() {
  scanf("%d%d%d%d", &n, &m[0], &m[1], &t);
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i <= m[j]; ++i) {
      scanf("%d", &x[j][i]);
    }
  }
}
void update(int j, int pos, int val, pair<int, int> par) {
  {
    if (!(pos < MAXN)) exit(0);
  };
  val = min(val, INF);
  if (dp[j][pos].val > val) {
    dp[j][pos] = state(val, par);
  }
}
void recover() {
  int i = coords.size() - 1;
  int j = dp[0][i].val < dp[1][i].val ? 0 : 1;
  if (dp[j][i].val < INF) {
    can = true;
    while (i > -1) {
      auto& st = dp[j][i];
      int pos = coords[i];
      if (st.par.first != j) {
        trans.push_back(pos);
      }
      if (i && x[j][ptr[i][j]] == coords[i]) {
        shots.push_back(pair<int, int>(j + 1, st.val));
      }
      j = st.par.first;
      i = st.par.second;
    }
  }
  reverse(trans.begin(), trans.end());
  while (!trans.empty() && trans.back() > n) {
    trans.pop_back();
  }
  reverse(shots.begin(), shots.end());
}
void solve() {
  dp[0][0] = state(0, pair<int, int>(0, -1));
  dp[1][0] = state(0, pair<int, int>(0, 0));
  coords.push_back(1);
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i <= m[j]; ++i) {
      if (x[j][i] > 1) {
        coords.push_back(x[j][i] - 1);
      }
      coords.push_back(x[j][i]);
      coords.push_back(x[j][i] + 1);
    }
  }
  coords.push_back(0);
  coords.push_back(n + 1);
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());
  for (int j = 0; j < 2; ++j) {
    int ptr = 0;
    for (int i = 0; i <= m[j]; ++i) {
      while (coords[ptr] < x[j][i]) {
        ++ptr;
      }
      posc[j][i] = ptr;
    }
  }
  for (int i = 1; i < coords.size(); ++i) {
    ptr[i][0] = ptr[i - 1][0];
    ptr[i][1] = ptr[i - 1][1];
    int pos = coords[i];
    for (int j = 0; j < 2; ++j) {
      while (ptr[i][j] <= m[j] && x[j][ptr[i][j]] < pos) {
        ++ptr[i][j];
      }
    }
    bool busy[2] = {x[0][ptr[i][0]] == pos, x[1][ptr[i][1]] == pos};
    for (int j = 0; j < 2; ++j) {
      dp[j][i] = state(INF, pair<int, int>(-1, -1));
      if (busy[j]) {
        int prv = x[j][ptr[i][j] - 1];
        int prv_pos = posc[j][ptr[i][j] - 1];
        int val = dp[j][prv_pos].val;
        if (val + t < pos) {
          update(j, i, val + t, pair<int, int>(j, prv_pos));
        }
        if (max(dp[j][prv_pos + 1].val + t, prv + 1) < pos) {
          update(j, i, max(dp[j][prv_pos + 1].val + t, prv + 1),
                 pair<int, int>(j, prv_pos + 1));
        }
      } else {
        update(j, i, dp[j][i - 1].val, pair<int, int>(j, i - 1));
      }
    }
    for (int j = 0; j < 2; ++j) {
      if (!busy[j]) {
        update(j, i, dp[j ^ 1][i].val, pair<int, int>(j ^ 1, i));
      }
    }
  }
  recover();
}
void print_answer() {
  if (can) {
    printf("Yes\n");
    printf("%d\n", trans.size());
    for (int i = 0; i < trans.size(); ++i) {
      printf("%d ", trans[i]);
    }
    printf("\n%d\n", shots.size());
    for (int i = 0; i < shots.size(); ++i) {
      printf("%d %d\n", shots[i].second, shots[i].first);
    }
  } else {
    printf("No\n");
  }
}
void run() {
  int t = 1;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
    print_answer();
  }
}
int main() {
  srand(90);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  run();
  return 0;
}
