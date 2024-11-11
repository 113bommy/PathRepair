#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct { int to, cost; };
const int MOD = 1e9 + 7;
const int iINF = 1e9;
const long long int llINF = 1e18;
const double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<int> graph[110];
bool visited[110];
int indeg[110];
vector<int> tsort(int N) {
  stack<int> sta;
  for (int i = 0; i < (N); i++)
    if (indeg[i] == 0) sta.push(i);
  vector<int> ans;
  while (!sta.empty()) {
    int now = sta.top();
    sta.pop();
    ans.push_back(now);
    for (int to : graph[now]) {
      indeg[to]--;
      if (indeg[to] == 0) sta.push(to);
    }
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> vec(N);
  for (int i = 0; i < (N); i++) cin >> vec[i];
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (N); j++) {
      if (vec[i] * 2 == vec[j]) {
        graph[i].push_back(j);
        indeg[j]++;
      }
      if (vec[i] / 3 == vec[j] && vec[i] % 3 == 0) {
        graph[i].push_back(j);
        indeg[j]++;
      }
    }
  }
  auto ans = tsort(N);
  for (auto x : ans) {
    cout << vec[x] << " ";
  }
  cout << endl;
  return 0;
}
