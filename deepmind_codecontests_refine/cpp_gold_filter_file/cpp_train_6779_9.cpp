#include <bits/stdc++.h>
using namespace std;
const long long modulo = 998244353;
const long long p = modulo;
vector<int> edges[300005];
int father[300005];
long long rCount[300005];
long long oCount[300005];
long long eCount[300005];
pair<int, int> gcd(long long a, long long b) {
  if (b == 0ll) return {1ll, 0ll};
  pair<int, int> q = gcd(b, a % b);
  return {q.second, q.first - q.second * (a / b)};
}
long long inv(long long a) {
  long long aa = gcd(a, p).first;
  aa %= p;
  if (aa < 0) aa += p;
  return aa;
}
void trace(int index) {
  for (int j = 0; j < edges[index].size(); ++j) {
    int v = edges[index][j];
    if (v == father[index]) {
      edges[index].erase(edges[index].begin() + j);
      --j;
      continue;
    }
    father[v] = index;
    trace(v);
  }
}
void dfs(int index) {
  if (edges[index].empty()) {
    rCount[index] = 1;
    oCount[index] = 1;
    eCount[index] = 0;
    return;
  }
  long long totalR = 1;
  long long total = 1;
  for (int j = 0; j < edges[index].size(); ++j) {
    int v = edges[index][j];
    dfs(v);
    totalR *= rCount[v];
    totalR %= modulo;
    total *= rCount[v] + eCount[v];
    total %= modulo;
  }
  rCount[index] = totalR;
  oCount[index] = 1;
  eCount[index] = 0;
  for (int j = 0; j < edges[index].size(); ++j) {
    int v = edges[index][j];
    long long temp = oCount[v] * total;
    temp %= modulo;
    temp *= inv(rCount[v] + eCount[v]);
    temp %= modulo;
    rCount[index] += temp;
    rCount[index] %= modulo;
    oCount[index] *= (rCount[v] + eCount[v]);
    oCount[index] %= modulo;
    eCount[index] += temp;
    eCount[index] %= modulo;
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%i%i", &u, &v);
    --u;
    --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    father[i] = -1;
    rCount[i] = 0;
    oCount[i] = 0;
    eCount[i] = 0;
  }
  father[0] = -1;
  trace(0);
  dfs(0);
  long long result = rCount[0];
  while (result < 0) {
    result += modulo;
  }
  result %= modulo;
  cout << result << endl;
  return 0;
}
