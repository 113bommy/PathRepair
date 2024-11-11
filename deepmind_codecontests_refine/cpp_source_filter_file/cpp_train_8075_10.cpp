#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
vector<int> e[100100];
int n, a[100100];
void input() {
  RI(n);
  for (int i = 0; i < int(n); i++) RI(a[i]);
  int x, y;
  for (int i = 0; i < int(n - 1); i++) {
    RI(x, y);
    x--, y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
}
pair<int, int> dfs(int pre, int now, long long& accu, int dig) {
  pair<int, int> cnt = make_pair(0, 0);
  int bit = (a[now] >> dig) & 1;
  vector<pair<int, int> > subCntArr;
  if (bit)
    cnt.first++;
  else
    cnt.second++;
  if (bit) accu++;
  for (auto next : e[now]) {
    if (next == pre) continue;
    pair<int, int> subCnt = dfs(now, next, accu, dig);
    accu += 1LL * subCnt.first * cnt.second + 1LL * subCnt.second * cnt.first;
    if (bit) {
      cnt.first += subCnt.second;
      cnt.second += subCnt.first;
    } else {
      cnt.first += subCnt.first;
      cnt.second += subCnt.second;
    }
    subCntArr.push_back(subCnt);
  }
  return cnt;
}
void solve() {
  long long ans = 0;
  for (int dig = 0; dig < int(5); dig++) {
    long long accu = 0;
    dfs(-1, 0, accu, dig);
    ans += 1LL * (1 << dig) * accu;
  }
  cout << ans << endl;
}
int main() {
  input();
  solve();
  return 0;
}
