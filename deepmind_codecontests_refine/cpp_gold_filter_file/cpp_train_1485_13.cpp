#include <bits/stdc++.h>
using namespace std;
const long long Inf = 1e10;
const long long MaxN = 2e5 + 5;
const long long md = 1e9 + 7;
vector<long long> Ans;
vector<pair<long long, long long> > Gr[MaxN];
bool used[MaxN];
long long W[MaxN];
long long S[MaxN];
void dfs(long long v) {
  for (pair<long long, long long> to : Gr[v]) {
    if (used[to.second]) continue;
    S[v]--;
    S[to.first]--;
    Ans.push_back(to.second + 1);
    used[to.second] = 1;
    if (S[to.first] <= W[to.first]) dfs(to.first);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < M; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    Gr[x].push_back({y, i});
    Gr[y].push_back({x, i});
    S[x]++;
    S[y]++;
  }
  for (int i = 0; i < N; i++) {
    if (S[i] <= W[i]) dfs(i);
  }
  if ((Ans).size() != M) {
    cout << "DEAD" << '\n';
  } else {
    cout << "ALIVE" << '\n';
    reverse((Ans).begin(), (Ans).end());
    for (long long a : Ans) {
      cout << a << ' ';
    }
  }
  return 0;
}
