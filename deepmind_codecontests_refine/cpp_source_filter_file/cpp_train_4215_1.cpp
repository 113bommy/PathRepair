#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int mod = 1e9 + 7;
int N, ar[30][30], used[30];
string s[MAXN];
vector<int> w;
void ts(int a) {
  used[a] = 1;
  for (int i = 1; i <= 26; i++)
    if (ar[a][i] && !used[i]) ts(i);
  w.push_back(a);
}
void dfs(int init, int a, int c) {
  if (c && a == init) {
    printf("Impossible\n");
    exit(0);
  }
  used[a] = 1;
  for (int i = 1; i <= 26; i++)
    if (ar[a][i] && (used[i] || i == init)) dfs(init, i, 1);
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> s[i];
  for (int i = 1; i < N; i++)
    for (int j = i + 1; j <= N; j++)
      for (int k = 0; k < (int)s[i].size() && k < (int)s[j].size(); k++) {
        if (s[i][k] != s[j][k]) {
          ar[s[i][k] - 'a' + 1][s[j][k] - 'a' + 1] = 1;
          break;
        }
        if (k == (int)s[j].size() - 1 && s[j].size() != s[i].size()) {
          printf("Impossible\n");
          return 0;
        }
      }
  for (int i = 1; i <= 26; i++) {
    memset(used, 0, sizeof used);
    dfs(i, i, 0);
  }
  memset(used, 0, sizeof used);
  for (int i = 1; i <= 26; i++)
    if (!used[i]) ts(i);
  reverse(w.begin(), w.end());
  for (int i = 0; i < 26; i++) printf("%c", w[i] + 'a' - 1);
  printf("\n");
  return 0;
}
