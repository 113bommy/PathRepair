#include <bits/stdc++.h>
using namespace std;
set<int> S;
void dfs(int Cur, int dgt, int x, int y) {
  if (dgt == 10) return;
  if (Cur > 0) S.insert(Cur);
  dfs(Cur * 10 + x, dgt + 1, x, y);
  dfs(Cur * 10 + y, dgt + 1, x, y);
  return;
}
int main() {
  int n, Ans = 0;
  cin >> n;
  S.insert(1e9);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      dfs(0, 1, i, j);
    }
  }
  for (auto x : S) {
    if (x > n)
      break;
    else
      Ans++;
  }
  cout << Ans << endl;
  return 0;
}
