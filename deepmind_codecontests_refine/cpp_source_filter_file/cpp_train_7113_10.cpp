#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, k;
bool check(int x) {
  int z = x, sm = 0, y = 1;
  while (int(z / y) != 0) {
    sm += int(z / y);
    y *= k;
  }
  if (sm >= n) return 1;
  return 0;
}
int main() {
  fast();
  cin >> n >> k;
  int l = 1, r = 1e9, md, ans;
  while (l <= r) {
    md = (l + r) / 2;
    if (check(md)) {
      ans = md;
      r = md - 1;
    } else
      l = md + 1;
  }
  cout << ans << endl;
}
