#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int n, l[N];
char s[N];
bool mrk[N], out = false;
void dfs(int pos) {
  mrk[pos] = true;
  int next;
  if (s[pos] == '>')
    next = pos + l[pos];
  else
    next = pos - l[pos];
  if (next <= 0 || next > n) {
    out = true;
    return;
  }
  if (!mrk[next]) dfs(next);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) cin >> l[i];
  dfs(1);
  if (out)
    cout << "FINITE" << '\n';
  else
    cout << "INFINITE" << '\n';
  return 0;
}
