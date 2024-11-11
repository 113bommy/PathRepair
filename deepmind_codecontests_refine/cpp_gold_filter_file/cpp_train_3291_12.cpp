#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f2f1f0f;
const long long LINF = 1ll * INF * INF;
const int MAX_M = 33, MAX_N = 65, MAX_S = 2550;
int M, Mr[MAX_M];
bool Dy[MAX_M][MAX_N][MAX_S];
int From[MAX_M][MAX_N][MAX_S];
inline bool isCan(int j, int s) { return s >= j * (j - 1) / 2; }
vector<int> Val;
void getList(int m, int j, int s) {
  if (m == 0) return;
  int i = From[m][j][s];
  Val.push_back(Mr[m]);
  if (i == m) return getList(m, j - 1, s - Mr[m]);
  return getList(m - 1, j - 1, s - Mr[m]);
}
int Ans[MAX_N][MAX_N];
int main() {
  cin >> M;
  for (int i = 1; i <= M; i++) scanf("%d", &Mr[i]);
  sort(Mr + 1, Mr + M + 1);
  Dy[0][0][0] = true;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < MAX_N; j++)
      for (int s = 0; s < MAX_S; s++) {
        if ((Dy[i - 1][j][s] || Dy[i][j][s]) && isCan(j + 1, s + Mr[i])) {
          Dy[i][j + 1][s + Mr[i]] = true;
          From[i][j + 1][s + Mr[i]] = (Dy[i][j][s] ? i : i - 1);
        }
      }
  }
  for (int j = 0; j < MAX_N; j++)
    if (Dy[M][j][j * (j - 1) / 2]) {
      getList(M, j, j * (j - 1) / 2);
      reverse((Val).begin(), (Val).end());
      int N = ((int)(Val).size());
      vector<pair<int, int> > W;
      for (int i = 0; i < N; i++) W.push_back(pair<int, int>(Val[i], i));
      for (int i = N - 1; i >= 0; i--) {
        int ix = W[i].second;
        int l = i - W[i].first;
        sort(W.begin(), W.begin() + i);
        for (int j = i - 1; j >= 0; j--) {
          int jx = W[j].second;
          if (l > 0) {
            W[j].first--, l--;
            Ans[jx][ix] = 1;
          } else
            Ans[ix][jx] = 1;
        }
      }
      printf("%d\n", N);
      for (int i = 0; i < N; i++, puts(""))
        for (int j = 0; j < N; j++) printf("%d", Ans[i][j]);
      return 0;
    }
  puts("=(");
  return 0;
}
