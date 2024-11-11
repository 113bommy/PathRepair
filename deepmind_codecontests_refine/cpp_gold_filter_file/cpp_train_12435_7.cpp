#include <bits/stdc++.h>
using namespace std;
int gs[55], sol[55][15];
long long ans = 0;
string str;
bool flag = false;
char s[55];
int l;
int df[55][10];
int f(int pos, int c) {
  if (pos == l) return 1;
  if (df[pos][c] != -1) return df[pos][c];
  int res = 0;
  int nn = c + s[pos];
  res += f(pos + 1, nn / 2);
  if (nn & 1) res += f(pos + 1, (nn + 1) / 2);
  return df[pos][c] = res;
}
bool good() {
  for (int i = 1; i < l; i++) {
    int nn = s[i] + s[i - 1];
    if (nn & 1) {
      if (nn / 2 != s[i] && (nn + 1) / 2 != s[i]) return false;
    } else {
      if (nn / 2 != s[i]) return false;
    }
  }
  return true;
}
int main() {
  memset(df, -1, sizeof(df));
  scanf("%s", s);
  l = strlen(s);
  for (int i = 0; i < l; i++) s[i] -= '0';
  long long ans = 0;
  for (int i = 0; i < 10; i++) ans += f(1, i);
  if (good()) ans--;
  cout << ans << endl;
  return 0;
}
