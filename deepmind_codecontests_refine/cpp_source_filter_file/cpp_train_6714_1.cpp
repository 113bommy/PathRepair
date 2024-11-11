#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
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
struct node {
  int child[26];
  node() {
    memset((child), -1, sizeof(child));
    ;
  }
};
vector<node> trie;
int init() {
  node x;
  trie.push_back(x);
  return (int)trie.size() - 1;
}
vector<int> v[2][800002];
bool chk[2][100001];
void add(int n, string &s, int i, int d, int cc, int ii) {
  v[cc][n].push_back(ii);
  if (i == s.length()) return;
  int c = s[i] - 'a';
  if (trie[n].child[c] == -1) {
    int next = init();
    trie[n].child[c] = next;
  }
  add(trie[n].child[c], s, i + 1, d + 1, cc, ii);
}
char temp[100001];
vector<pair<int, int> > res;
long long ans;
void find(int n, int d) {
  for (int(i) = (0); (i) <= (25); (i) += (1))
    if (trie[n].child[i] != -1) find(trie[n].child[i], d + 1);
  bool ok = 1;
  while (ok) {
    ok = 0;
    while (!v[0][n].empty() && chk[0][v[0][n].back()]) v[0][n].pop_back();
    while (!v[1][n].empty() && chk[1][v[1][n].back()]) v[1][n].pop_back();
    if (v[0][n].size() && v[1][n].size()) {
      ok = 1;
      int x = v[0][n].back(), y = v[1][n].back();
      ans += d;
      res.push_back(make_pair(x, y));
      chk[0][x] = chk[1][y] = 1;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    scanf("%s", temp);
    string s = temp;
    add(0, s, 0, 0, 0, i + 1);
  }
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    scanf("%s", temp);
    string s = temp;
    add(0, s, 0, 0, 1, i + 1);
  }
  find(0, 0);
  printf("%lld\n", ans);
  for (pair<int, int> p : res) printf("%d %d\n", p.first, p.second);
}
