#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100005;
unsigned long long F[N], H[N];
long long in[N], ara[N];
int n;
unsigned long long hs = 3797;
unsigned long long seg(int x, int y) { return H[y] - F[y - x + 1] * H[x - 1]; }
vector<int> g[N];
int main() {
  F[0] = 1;
  for (int i = 1; i < N; i++) F[i] = F[i - 1] * hs;
  cin >> n;
  map<int, int> mp;
  int id = 1;
  for (int i = 1; i <= n; i++) {
    cin >> in[i];
    ara[i] = in[i];
    if (mp[in[i]] == 0) {
      mp[in[i]] = id++;
    }
    in[i] = mp[in[i]];
    g[in[i]].push_back(i);
  }
  H[0] = 0;
  for (int i = 1; i <= n + 1; i++) H[i] = H[i - 1] * hs + in[i];
  priority_queue<pair<int, int>> Q;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      for (int k = j + 1; k < g[i].size(); k++) {
        int l = g[i][j];
        int r = g[i][k];
        int len = r - l;
        if (r + len - 1 > n) continue;
        if (seg(l, r - 1) == seg(r, r + len - 1)) {
          Q.push(make_pair(len, l));
        }
      }
    }
  }
  int done = 0;
  while (!Q.empty()) {
    pair<int, int> P = Q.top();
    Q.pop();
    if (done < P.second) {
      done = P.second + P.first - 1;
    }
  }
  cout << n - done << "\n";
  for (int i = done + 1; i <= n; i++) cout << ara[i] << " ";
}
