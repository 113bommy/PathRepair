#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long MOD = 1e9 + 7;
inline void read(int &x) {
  x = 0;
  char c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  }
}
long long quick_mod(long long A, long long B) {
  long long ret = 1;
  A %= MOD;
  while (B) {
    if (B & 1) ret = ret * A % MOD;
    B >>= 1;
    A = A * A % MOD;
  }
  return ret;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int MAXN = 35;
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};
int N, M;
char mrt[MAXN][MAXN];
pair<pair<int, int>, pair<int, int> > domino[30];
map<pair<int, int>, pair<int, int> > dom;
int domino_sz = 0;
pair<int, int> a4[20];
int a4_sz = 0;
int a4_index[20][4];
int a4_cut[MAXN][MAXN];
int a4_dfs[MAXN][MAXN];
int a4_domino[MAXN][MAXN];
bool a4_fixed[MAXN][MAXN];
char a4_ans[MAXN][MAXN];
bool assigned = 0;
int col[10];
bool infield(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; }
vector<int> infixed;
int ans = 0;
void output() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a4_dfs[i][j] == -2) {
        cout << '.';
      } else if (a4_dfs[i][j] == -1) {
        cout << '?';
      } else {
        cout << a4_dfs[i][j];
      }
    }
    cout << endl;
  }
  cout << endl;
}
bool chk() {
  bool used[50];
  memset(used, 0, sizeof(used));
  for (int i = 0; i < domino_sz; i++) {
    int x1 = domino[i].first.first, sidiuasdnom = domino[i].first.second,
        x2 = domino[i].second.first, y2 = domino[i].second.second;
    int c1 = a4_dfs[x1][sidiuasdnom], c2 = a4_dfs[x2][y2];
    if (used[c1 * 7 + c2] || used[c1 + c2 * 7]) {
      return 0;
    }
    used[c1 * 7 + c2] = used[c2 * 7 + c1] = 1;
  }
  return 1;
}
void dfs(int pos) {
  if (pos == infixed.size()) {
    if (chk()) {
      ans++;
      if (!assigned) {
        assigned = 1;
        for (int i = 0; i < N; i++) {
          for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
              if (a4_dfs[i][j] == -2) {
                a4_ans[i][j] = '.';
              } else {
                a4_ans[i][j] = '0' + a4_dfs[i][j];
              }
            }
          }
        }
      }
    }
    return;
  }
  int x = a4[infixed[pos]].first, y = a4[infixed[pos]].second;
  for (int c = 0; c < 7; c++)
    if (col[c] > 0) {
      a4_dfs[x][y] = a4_dfs[x + 1][y] = a4_dfs[x][y + 1] =
          a4_dfs[x + 1][y + 1] = c;
      col[c]--;
      dfs(pos + 1);
      col[c]++;
    }
}
int jc(int i) {
  int ret = 1;
  while (i > 1) {
    ret *= i;
    i--;
  }
  return ret;
}
int main(void) {
  read(N);
  read(M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) mrt[i][j] = getchar();
    getchar();
  }
  for (int i = 0; i < 7; i++) col[i] = 2;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (mrt[i][j] == '.') {
        a4_domino[i][j] = -1;
        a4_cut[i][j] = -2;
      } else {
        a4_cut[i][j] = -1;
      }
    }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (mrt[i][j] != '.') {
        for (int k = 0; k < 2; k++)
          if (infield(i + dx[k], j + dy[k])) {
            if (mrt[i][j] == mrt[i + dx[k]][j + dy[k]]) {
              domino[domino_sz] =
                  make_pair(make_pair(i, j), make_pair(i + dx[k], j + dy[k]));
              a4_domino[i][j] = a4_domino[i + dx[k]][j + dy[k]] = domino_sz;
              domino_sz++;
              break;
            }
          }
      }
  for (int i = 0; i < N; i++) {
    int j = 0;
    while (j < M) {
      if (a4_cut[i][j] == -1) {
        a4[a4_sz] = make_pair(i, j);
        a4_cut[i][j] = a4_cut[i + 1][j] = a4_cut[i][j + 1] =
            a4_cut[i + 1][j + 1] = a4_sz;
        a4_index[a4_sz][0] = a4_domino[i][j];
        a4_index[a4_sz][1] = a4_domino[i + 1][j];
        a4_index[a4_sz][2] = a4_domino[i][j + 1];
        a4_index[a4_sz][3] = a4_domino[i + 1][j + 1];
        a4_sz++;
        j += 2;
      } else {
        j++;
      }
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (mrt[i][j] == '.')
        a4_dfs[i][j] = -2;
      else
        a4_dfs[i][j] = -1;
    }
  for (int i = 0; i < domino_sz; i++) {
    dom[domino[i].first] = domino[i].second;
    dom[domino[i].second] = domino[i].first;
  }
  vector<int> fixed;
  for (int i = 0; i < a4_sz; i++) {
    int x = a4[i].first, y = a4[i].second;
    col[fixed.size()]--;
    if (a4_domino[x][y] == a4_domino[x + 1][y]) {
      a4_dfs[x][y] = a4_dfs[x + 1][y] = a4_dfs[x][y + 1] =
          a4_dfs[x + 1][y + 1] = (int)fixed.size();
      fixed.push_back(i);
      a4_fixed[x][y] = a4_fixed[x + 1][y] = a4_fixed[x][y + 1] =
          a4_fixed[x + 1][y + 1] = 1;
    } else if (a4_domino[x][y] == a4_domino[x][y + 1]) {
      a4_dfs[x][y] = a4_dfs[x + 1][y] = a4_dfs[x][y + 1] =
          a4_dfs[x + 1][y + 1] = (int)fixed.size();
      fixed.push_back(i);
      a4_fixed[x][y] = a4_fixed[x + 1][y] = a4_fixed[x][y + 1] =
          a4_fixed[x + 1][y + 1] = 1;
    } else if (a4_domino[x + 1][y] == a4_domino[x + 1][y + 1]) {
      a4_dfs[x][y] = a4_dfs[x + 1][y] = a4_dfs[x][y + 1] =
          a4_dfs[x + 1][y + 1] = (int)fixed.size();
      fixed.push_back(i);
      a4_fixed[x][y] = a4_fixed[x + 1][y] = a4_fixed[x][y + 1] =
          a4_fixed[x + 1][y + 1] = 1;
    } else if (a4_domino[x][y + 1] == a4_domino[x + 1][y + 1]) {
      a4_dfs[x][y] = a4_dfs[x + 1][y] = a4_dfs[x][y + 1] =
          a4_dfs[x + 1][y + 1] = (int)fixed.size();
      fixed.push_back(i);
      a4_fixed[x][y] = a4_fixed[x + 1][y] = a4_fixed[x][y + 1] =
          a4_fixed[x + 1][y + 1] = 1;
    } else {
      col[fixed.size()]++;
      infixed.push_back(i);
    }
  }
  dfs(0);
  int dif = infixed.size() - 7;
  ans /= jc(dif);
  long long ANS = ans * (long long)5040;
  write(ANS);
  putchar('\n');
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      putchar(a4_ans[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
