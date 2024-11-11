#include <bits/stdc++.h>
using namespace std;
int n, m;
int pLen;
char str[200];
char mat[200];
char ans[200];
bool isMatch(int idx) {
  if (pLen + idx > n) return false;
  for (int i = 0; i < pLen; i++)
    if (str[i] != ans[i + idx]) return false;
  return true;
}
bool check(int idx) {
  if (idx < 0) return true;
  if (ans[idx] != -1) {
    if (ans[idx] == '0' && isMatch(idx)) return false;
    return check(idx - 1);
  }
  for (int i = 0; i < m; i++) {
    ans[idx] = 'a' + i;
    if (!isMatch(idx))
      if (check(idx - 1)) return true;
  }
  return false;
}
void solve() {
  bool vaild = true;
  pLen = strlen(str);
  for (int i = n - pLen + 1; i < n; i++) mat[i] = '0';
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n && vaild; i++) {
    if (mat[i] == '1') {
      for (int j = 0; j < pLen && vaild; j++) {
        if (ans[i + j] != -1 && ans[i + j] != str[j])
          vaild = false;
        else
          ans[i + j] = str[j];
      }
    }
  }
  if (vaild && check(n)) {
    for (int i = 0; i < n; i++) cout << ans[i];
  } else
    cout << "No solution";
  cout << endl;
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    cin >> str;
    cin >> mat;
    solve();
  }
  return 0;
}
