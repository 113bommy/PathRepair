#include <bits/stdc++.h>
using namespace std;
struct circle {
  long long x;
  long long y;
  long long r;
};
long long dot(pair<long long, long long> u, pair<long long, long long> v) {
  return u.first * v.first + u.second * v.second;
}
bool check(circle c, long long r, long long d) {
  double dist = sqrt(dot(pair<long long, long long>(c.x, c.y),
                         pair<long long, long long>(c.x, c.y)));
  double left = dist - c.r;
  double right = dist + c.r;
  return r - d <= left && right <= r;
}
long long GCD(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return GCD(b % a, a);
}
vector<long long> ar;
vector<long long> gcd;
vector<long long> depth;
vector<long long> divi;
void DFS1(vector<vector<long long> >& G, vector<long long>& visited,
          long long u, long long par) {
  visited[u] = true;
  if (u != par) {
    gcd[u] = GCD(ar[u], gcd[par]);
  }
  depth[u] = depth[par] + 1;
  for (long long i = 0; i < G[u].size(); i++) {
    long long v = G[u][i];
    if (!visited[v]) DFS1(G, visited, v, u);
  }
}
void DFS2(vector<vector<long long> >& G, vector<long long>& visited,
          long long u, long long par, vector<long long>& checkList) {
  visited[u] = true;
  for (long long i = 0; i < checkList.size(); i++) {
    divi[i] += (ar[u] % checkList[i] == 0);
    if (divi[i] >= depth[u] - 1) gcd[u] = max(gcd[u], checkList[i]);
  }
  for (long long i = 0; i < G[u].size(); i++) {
    long long v = G[u][i];
    if (!visited[v]) DFS2(G, visited, v, u, checkList);
  }
  for (long long i = 0; i < checkList.size(); i++) {
    divi[i] -= (ar[u] % checkList[i] == 0);
  }
}
int main() {
  long long n;
  cin >> n;
  ar = vector<long long>(n);
  vector<vector<long long> > G(n);
  for (long long i = 0; i < n; i++) cin >> ar[i];
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<long long> checkList;
  for (long long i = 1; i * i <= ar[0]; i++) {
    if (ar[0] % i == 0) {
      checkList.push_back(ar[0] / i);
      checkList.push_back(i);
    }
  }
  gcd = vector<long long>(n);
  vector<long long> visited(n);
  depth = vector<long long>(n);
  DFS1(G, visited, 0, 0);
  divi = vector<long long>(checkList.size());
  visited = vector<long long>(n);
  DFS2(G, visited, 0, 0, checkList);
  for (long long i = 0; i < n; i++) {
    cout << gcd[i] << " ";
  }
  cout << endl;
}
