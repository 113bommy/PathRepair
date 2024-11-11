#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int n, m, k;
pair<int, int> p[500000];
map<long long, vector<int> > M;
long long ans;
long long pow2[500001], a[500001];
int parent[500001];
int find(int a) {
  if (parent[a] < 0) return a;
  return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) {
    parent[a] += parent[b];
    parent[b] = a;
  }
}
int main() {
  memset((parent), -1, sizeof(parent));
  ;
  scanf("%d%d%d", &n, &m, &k);
  for (int(i) = (1); (i) <= (n); (i) += (1)) scanf("%lld", a + i);
  pow2[0] = 1;
  for (int(i) = (1); (i) <= (500000); (i) += (1))
    pow2[i] = (pow2[i - 1] * 2) % MOD;
  for (int(i) = (0); (i) <= (m - 1); (i) += (1)) {
    scanf("%d%d", &p[i].first, &p[i].second);
    M[a[p[i].first] ^ a[p[i].second]].push_back(i);
  }
  long long cc = (1LL << k);
  for (auto it = M.begin(); it != M.end(); it++) {
    cc--;
    stack<int> st;
    vector<int> &v = it->second;
    int com = n;
    for (int i : v) {
      st.push(i);
      int x, y;
      tie(x, y) = p[i];
      x = find(x), y = find(y);
      if (x != y) {
        com--;
        merge(x, y);
      }
    }
    ans = (ans + pow2[com]) % MOD;
    while (!st.empty()) {
      parent[p[st.top()].first] = -1;
      parent[p[st.top()].second] = -1;
      st.pop();
    }
  }
  cc %= MOD;
  ans = (ans + cc * pow2[n]) % MOD;
  printf("%lld", ans);
}
