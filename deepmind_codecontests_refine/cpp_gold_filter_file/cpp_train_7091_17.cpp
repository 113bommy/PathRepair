#include <bits/stdc++.h>
using namespace std;
const int mod = 12345;
int n, j, k, l, i, o, p, __t;
long long m;
pair<int, int> query[100];
string s;
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && (ch != '-'); ch = getchar())
    ;
  if (ch == '-')
    a = 0, __t = -1;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a *= __t;
}
void mul() {}
int deg[1000], size, ans;
map<vector<int>, int> num;
vector<int> A;
bool char_exist[100];
int Map[200][200], correct[200], F[200][200], ANS[200][200];
void DFS(int P, int s) {
  if (P == n + 1) {
    if (s == 0) {
      num[A] = ++size;
      return;
    }
    if (s == 1) {
      int temp = num[A];
      for (int i = (0); i <= (25); i++)
        if (char_exist[i]) {
          vector<int> B = A;
          for (int j = (1); j <= (n); j++)
            if (i == query[j].first) B[j] = (B[j] + 1) % query[j].second;
          Map[temp][num[B]] += 1;
        }
      return;
    }
    if (s == 2) {
      bool could = 1;
      for (int i = (0); i <= (25); i++)
        if (char_exist[i] && correct[i] == 0) could = 0;
      ans = (ans + could * F[1][num[A]]) % mod;
    }
  }
  for (int i = (0); i <= (query[P].second - 1); i++) {
    A[P] = i;
    if (i == 0) correct[query[P].first]++;
    DFS(P + 1, s);
    if (i == 0) correct[query[P].first]--;
  }
}
void build_mat() {
  for (int i = 1; i <= n; i++) char_exist[query[i].first] = 1;
  for (int i = (1); i <= (n + 1); i++) A.push_back(0);
  DFS(1, 0);
  DFS(1, 1);
}
int temp[200][200];
void quick() {
  for (int i = (1); i <= (size); i++) ANS[1][1] = 1;
  for (long long i = 1; i <= m; i *= 2) {
    if (m & i) {
      memset(temp, 0, sizeof temp);
      for (int i = (1); i <= (size); i++)
        for (int j = (1); j <= (size); j++)
          for (int k = (1); k <= (size); k++)
            temp[i][k] = (temp[i][k] + ANS[i][j] * Map[j][k]) % mod;
      for (int i = (1); i <= (size); i++)
        for (int j = (1); j <= (size); j++) ANS[i][j] = temp[i][j];
    }
    memset(temp, 0, sizeof temp);
    for (int i = (1); i <= (size); i++)
      for (int j = (1); j <= (size); j++)
        for (int k = (1); k <= (size); k++)
          temp[i][k] = (temp[i][k] + Map[i][j] * Map[j][k]) % mod;
    for (int i = (1); i <= (size); i++)
      for (int j = (1); j <= (size); j++) Map[i][j] = temp[i][j];
  }
}
void solve() {
  F[1][1] = 1;
  quick();
  memset(temp, 0, sizeof temp);
  for (int i = (1); i <= (1); i++)
    for (int j = (1); j <= (size); j++)
      for (int k = (1); k <= (size); k++)
        temp[i][k] = (temp[i][k] + F[i][j] * ANS[j][k]) % mod;
  for (int i = (1); i <= (size); i++) F[1][i] = temp[1][i];
  DFS(1, 2);
}
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s >> k;
    query[i] = make_pair(s[0] - 'A', k);
  }
  if (m == 0) {
    printf("1\n");
    return 0;
  }
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  build_mat();
  solve();
  cout << ans << endl;
}
