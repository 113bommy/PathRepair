#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
#pragma GCC optimize("O500")
using namespace std;
const bool db = false;
int a[100100];
int main() {
  ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  int cnt = 1, eq = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i + 1]) cnt++;
    if (a[i] == a[i + 1]) eq++;
  }
  if (eq >= 2)
    cnt += 2;
  else
    cnt += eq;
  cout << cnt << '\n';
  return 0;
}
