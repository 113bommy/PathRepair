#include <bits/stdc++.h>
using namespace std;
int l[805], r[805], sum[1605][10][2005], f[1605][2005], ch[1605][10], cnt,
    fail[1605];
string str, str2;
void insert(int *s, int len, int v) {
  if (!s[1]) return;
  int now = 0;
  for (int i = 1; i <= len; i++) {
    for (int j = (now == 0); j < s[i]; j++) sum[now][j][len - i] += v;
    if (!ch[now][s[i]]) ch[now][s[i]] = ++cnt;
    if (i == len) sum[now][s[i]][0] += v;
    now = ch[now][s[i]];
  }
}
queue<int> q;
void build() {
  for (int i = 0; i <= 9; i++)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int j = 0; j <= 9; j++)
      if (ch[now][j])
        fail[ch[now][j]] = ch[fail[now]][j], q.push(ch[now][j]);
      else
        ch[now][j] = ch[fail[now]][j];
  }
}
int main() {
  int n;
  cin >> str >> str2 >> n;
  str[str.size() - 1]--;
  for (int i = str.size() - 1; i >= 1; i--)
    if (str[i] < '0')
      str[i] = '9', str[i - 1]--;
    else
      break;
  if (str[0] == '0') {
    for (int i = 0; i < str.size() - 1; i++) str[i] = str[i + 1];
    str.pop_back();
  }
  for (int i = 1; i <= str.size(); i++) l[i] = str[i - 1] - '0';
  for (int i = 1; i <= str2.size(); i++) r[i] = str2[i - 1] - '0';
  insert(l, str.size(), -1), insert(r, str2.size(), 1);
  build();
  for (int i = 1; i <= cnt; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k < str2.size(); k++) sum[i][j][k] += sum[fail[i]][j][k];
  for (int i = 0; i <= cnt; i++)
    for (int j = 1; j <= 9; j++)
      for (int k = max((int)str.size() - 1, 0); k < str2.size() - 1; k++)
        sum[i][j][k]++;
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 1; k < n; k++) sum[i][j][k] += sum[i][j][k - 1];
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j < n; j++) f[i][j] = -1e9;
  for (int k = n - 1; k >= 0; k--) {
    for (int i = 0; i <= cnt; i++) {
      for (int j = 0; j <= 9; j++)
        f[i][k] = max(f[i][k], f[ch[i][j]][k + 1] + sum[i][j][n - k - 1]);
    }
  }
  printf("%d\n", f[0][0]);
  int now = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 9; j++)
      if (f[now][i] == f[ch[now][j]][i + 1] + sum[now][j][n - i - 1]) {
        printf("%d", j);
        now = ch[now][j];
        break;
      }
  return 0;
}
