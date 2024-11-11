#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return x * f;
}
int vis[N];
vector<int> prime;
void Sieve(int n) {
  for (int i = 2; i <= n; ++i)
    if (!vis[i]) {
      prime.push_back(i);
      for (int j = i + i; j <= n; j += i) vis[j] = 1;
    }
}
map<int, int> SG;
int dfs(int x) {
  if (!x)
    return 0;
  else if (SG.count(x))
    return SG[x];
  set<int> S;
  for (int i = 0; i < 32; ++i)
    if (x >> i) S.insert(dfs((x >> (i + 1)) | (x & ((1 << i) - 1))));
  for (int i = 0;; ++i)
    if (!S.count(i)) return SG[i] = i;
}
map<int, set<int> > M;
int main() {
  int n = read();
  Sieve(1e5);
  for (int i = 1; i <= n; ++i) {
    int x = read();
    for (int p : prime) {
      if (x % p == 0) {
        int cnt = 0;
        while (x % p == 0) ++cnt, x /= p;
        M[p].insert(cnt);
      }
      if (x == 0) break;
    }
    if (x > 1) M[x].insert(1);
  }
  int ans = 0;
  for (auto S : M) {
    int temp = 0;
    for (int i : S.second) temp |= (1 << (i - 1));
    ans ^= dfs(temp);
  }
  puts(ans ? "Mojtaba" : "Arpa");
  return 0;
}
