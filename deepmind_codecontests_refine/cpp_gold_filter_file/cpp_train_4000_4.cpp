#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a;
  cin >> n >> m;
  vector<int> cost(m);
  for (int i = 0; i < m; i++) cin >> a >> cost[i];
  sort(cost.begin(), cost.end(), greater<int>());
  int k = 1;
  while (true) {
    int nxtk = k + 1;
    int need = nxtk * (nxtk - 1) / 2;
    if (nxtk % 2 == 0) need += nxtk / 2 - 1;
    if (need <= (n - 1) && nxtk <= m)
      k = nxtk;
    else
      break;
  }
  long long res = 0;
  for (int i = 0; i < k; i++) res += cost[i];
  cout << res;
}
