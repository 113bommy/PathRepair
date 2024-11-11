#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-11;
struct subject {
  long long a, b, c;
  int ind;
  bool operator<(const subject &o) const { return c < o.c; }
};
long long dp[55][55][110];
long long dp2[55][55][110];
int main() {
  int N, M, K;
  long long ax1, ax2, ax3;
  subject s[60];
  for (; ~scanf("%d%d%d", &N, &M, &K);) {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < M; i++) {
      cin >> ax1 >> ax2 >> ax3;
      s[i].a = ax1;
      s[i].b = ax2;
      s[i].c = ax3;
      s[i].ind = i + 1;
    }
    sort(s, s + M);
    for (int k = 0; k < M; k++) {
      for (long long i = s[k].a; i <= s[k].b; i++) {
        dp[0][k][i - s[k].a] = 1;
        dp2[0][k][i - s[k].a] = i;
      }
    }
    for (int i = 1; i < N; i++) {
      for (int k = i; k < M; k++) {
        for (long long j = s[k].a; j <= s[k].b; j++) {
          dp[i][k][j - s[k].a] = 0;
          dp2[i][k][j - s[k].a] = 0;
          for (int l = 0; l < k && s[l].c < s[k].c; l++) {
            if (j - K <= s[l].b && j - K >= s[l].a &&
                dp[i - 1][l][j - K - s[l].a]) {
              if (dp2[i][k][j - s[k].a] < j + dp2[i - 1][l][j - K - s[l].a]) {
                dp[i][k][j - s[k].a] = (l + 1);
                dp2[i][k][j - s[k].a] = j + dp2[i - 1][l][j - K - s[l].a];
              }
            }
            if (j % K == 0 && j / K <= s[l].b && j / K >= s[l].a &&
                dp[i - 1][l][(j / K) - s[l].a]) {
              if (dp2[i][k][j - s[k].a] < j + dp[i - 1][l][(j / K) - s[l].a]) {
                dp[i][k][j - s[k].a] = (M + 5) * (l + 1);
                dp2[i][k][j - s[k].a] = j + dp[i - 1][l][(j / K) - s[l].a];
              }
            }
          }
        }
      }
    }
    bool voy = false;
    int posi;
    long long posj;
    long long mxx = 0;
    for (int i = 0; i < M; i++) {
      for (long long j = s[i].a; j <= s[i].b; j++) {
        if (mxx < dp2[N - 1][i][j - s[i].a]) {
          voy = true;
          mxx = dp2[N - 1][i][j - s[i].a];
          posi = i;
          posj = j;
        }
      }
    }
    if (!voy) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      stack<pair<int, long long> > pila;
      pair<int, long long> actual;
      int ptr;
      int day = N;
      int sub;
      long long pnts;
      pila.push(pair<int, long long>(posi, posj));
      while (pila.size() != N) {
        day -= 1;
        actual = pila.top();
        ptr = dp[day][actual.first][actual.second - s[actual.first].a];
        if (ptr > M + 2) {
          sub = (ptr) / (M + 5) - 1;
          pnts = actual.second / K;
        } else {
          sub = (ptr)-1;
          pnts = actual.second - K;
        }
        pila.push(pair<int, long long>(sub, pnts));
      }
      while (!pila.empty()) {
        actual = pila.top();
        pila.pop();
        cout << s[actual.first].ind << " " << actual.second << endl;
      }
    }
  }
  return 0;
}
