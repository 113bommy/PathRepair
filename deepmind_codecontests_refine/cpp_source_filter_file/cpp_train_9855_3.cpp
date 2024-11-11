#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
bool dfs(int dep, int n, int cnt4, int cnt7, int src) {
  if (dep == 0) {
    if (n >= src && cnt4 == cnt7) {
      ans = n;
      return true;
    }
    return false;
  }
  if (dfs(dep - 1, n * 10 + 4, cnt4 + 1, cnt7, src)) return true;
  if (dfs(dep - 1, n * 10 + 7, cnt4, cnt7 + 1, src)) return true;
  return false;
}
void process(int n) {
  string num = "";
  int tmp = n;
  while (tmp) {
    num += (tmp % 10) + '0';
    tmp /= 10;
  }
  reverse(num.begin(), num.end());
  int ns = num.size();
  if (ns & 1) ns++;
  for (int i = 0; i < ns / 2; i++) ans = ans * 10 + 7;
  for (int i = 0; i < ns / 2; i++) ans = ans * 10 + 4;
  if (ans < n) ns += 2;
  ans = 0;
  if ((int)num.size() < ns) {
    for (int i = 0; i < ns / 2; i++) ans = ans * 10 + 4;
    for (int i = 0; i < ns / 2; i++) ans = ans * 10 + 7;
    cout << ans << endl;
    return;
  }
  dfs(ns, 0, 0, 0, n);
  cout << ans << endl;
}
int main() {
  int n;
  while (cin >> n) {
    process(n);
  }
}
