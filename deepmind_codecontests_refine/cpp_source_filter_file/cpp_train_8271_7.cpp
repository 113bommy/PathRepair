#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int MAXP = 10005 * 2;
struct item {
  int C;
  int H;
};
int N, P;
int Q;
int E;
vector<pair<int, int> > V[MAXP];
vector<pair<int, int> > query[MAXP];
int pref[MAXP];
vector<pair<int, int> > R1;
vector<pair<int, int> > R2;
int DP1[MAXN][MAXN];
int DP2[MAXN][MAXN];
int ans[MAXN];
int main() {
  scanf("%d%d", &N, &P);
  for (int i = 1; i <= N; i++) {
    int C, H, T;
    scanf("%d%d%d", &C, &H, &T);
    V[T].push_back(pair<int, int>(C, H));
    E = max(E, T);
  }
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    query[a].push_back(pair<int, int>(b, i));
  }
  for (int i = 1; i < MAXP; i++) {
    pref[i] = pref[i - 1] + V[i].size();
  }
  for (int T = 1; T <= E + P - 1; T += P) {
    R1.clear();
    R1.push_back(pair<int, int>(0, 0));
    R2.clear();
    R2.push_back(pair<int, int>(0, 0));
    for (int i = T; i > max(0, T - P); i--) {
      for (int j = 0; j < V[i].size(); j++) {
        R1.push_back(V[i][j]);
      }
    }
    for (int i = T + 1; i < min(E + 1, T + P); i++) {
      for (int j = 0; j < V[i].size(); j++) {
        R2.push_back(V[i][j]);
      }
    }
    memset(DP1, 0, sizeof(DP1));
    memset(DP2, 0, sizeof(DP2));
    for (int i = 1; i < R1.size(); i++) {
      for (int j = 1; j < MAXN; j++) {
        DP1[i][j] = max(DP1[i][j], DP1[i - 1][j]);
        if (j - R1[i].first >= 0) {
          DP1[i][j] =
              max(DP1[i][j], DP1[i - 1][j - R1[i].first] + R1[i].second);
        }
      }
    }
    for (int i = 1; i < R2.size(); i++) {
      for (int j = 1; j < MAXN; j++) {
        DP2[i][j] = max(DP2[i][j], DP2[i - 1][j]);
        if (j >= R2[i].first) {
          DP2[i][j] =
              max(DP2[i][j], DP2[i - 1][j - R2[i].first] + R2[i].second);
        }
      }
    }
    for (int i = T; i < min(MAXP, T + P); i++) {
      for (int j = 0; j < query[i].size(); j++) {
        int ix = query[i][j].second;
        int B = query[i][j].first;
        int X = pref[T] - pref[max(i - P, 0)];
        int Y = pref[i] - pref[T];
        for (int k = 0; k <= B; k++) {
          ans[ix] = max(ans[ix], DP1[X][k] + DP2[Y][B - k]);
        }
      }
    }
  }
  for (int i = 1; i <= Q; i++) {
    printf("%d\n", ans[i]);
  }
}
