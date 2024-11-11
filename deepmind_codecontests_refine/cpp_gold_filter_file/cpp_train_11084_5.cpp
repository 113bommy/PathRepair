#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
inline bool REMIN(T& a, const S& b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool REMAX(T& a, const S& b) {
  return a < b ? a = b, 1 : 0;
}
int bit(long long x, int pos) { return (x >> pos) & 1; }
long long power(long long base, long long exp, long long c = 1e9 + 7) {
  if (!exp) return 1;
  long long r = power(base, exp >> 1, c);
  r = (r * r) % c;
  if (exp & 1) r = (r * base) % c;
  return r;
}
long long T, N, M, K;
int a, b, c;
string s1, s2;
const long double PI = 2 * acos(0);
const long long INF = 1e9 + 4;
const int NMAX = 1e5 + 5;
const long long MOD = 1000000007;
int vis[NMAX];
int yay[NMAX];
vector<int> eds[NMAX];
vector<int> act[NMAX];
map<pair<int, int>, int> exi;
vector<int> chek;
void roam(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  chek.emplace_back(x);
  for (int v : eds[x]) roam(v);
}
int low[NMAX], disc[NMAX], ver[NMAX];
bool dfs(int x) {
  low[x] = 1;
  for (int v : act[x]) {
    if (low[v]) {
      if (low[v] == 1) return 1;
    } else {
      if (dfs(v)) return 1;
    }
  }
  low[x] = 2;
  return 0;
}
int inc[NMAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int(i) = int(1); (i) <= int(M); ++(i)) {
    cin >> a >> b;
    if (!exi[{a, b}]) {
      eds[a].emplace_back(b);
      eds[b].emplace_back(a);
      exi[{a, b}] = 1;
    }
    act[a].emplace_back(b);
    inc[b]++;
  }
  long long ans = 0;
  for (int(i) = int(1); (i) <= int(N); ++(i)) {
    if (!vis[i]) {
      chek.clear();
      roam(i);
      int tot = 0, root = 0;
      for (int x : chek)
        if (!inc[x]) root = x;
      if (!root) {
        ans += ((int)(chek.size()));
      } else {
        int flag = 0;
        for (int gofor : chek)
          if (!disc[gofor]) {
            if (dfs(gofor)) {
              flag = 1;
            }
          }
        if (flag)
          ans += ((int)(chek.size()));
        else
          ans += ((int)(chek.size())) - 1;
      }
    }
  }
  cout << ans;
  return 0;
}
