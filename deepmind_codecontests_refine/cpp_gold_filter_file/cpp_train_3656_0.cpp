#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
int last[505][5005];
pair<int, int> par[505][5050];
void print(int mod, int sum) {
  if (last[mod][sum] == -1) return;
  print(par[mod][sum].first, par[mod][sum].second);
  cout << last[mod][sum];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int d, s;
  cin >> d >> s;
  queue<pair<int, int>> Q;
  memset(last, -1, sizeof last);
  for (int i = 1; i <= 9; i++) {
    Q.push({i % d, i});
    last[i % d][i] = i;
    par[i % d][i] = {0, 0};
  }
  while (!Q.empty()) {
    int mod = Q.front().first, sum = Q.front().second;
    Q.pop();
    if (sum > s) continue;
    for (int i = 0; i <= 9; i++) {
      int nmod = (mod * 10 + i) % d;
      int nsum = sum + i;
      if (last[nmod][nsum] != -1) continue;
      last[nmod][nsum] = i;
      par[nmod][nsum] = {mod, sum};
      Q.push({nmod, nsum});
    }
  }
  if (last[0][s] == -1)
    cout << -1;
  else
    print(0, s);
}
