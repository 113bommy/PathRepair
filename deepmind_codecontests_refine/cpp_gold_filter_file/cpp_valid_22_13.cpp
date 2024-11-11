#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
long long f[45][45], st[45], siz[45], q[45], n, k, ful;
long long popcnt(long long x) { return __builtin_popcountll(x); }
long long lowbit(long long x) { return x & (-x); }
void dfs(long long dep, long long cur) {
  if (dep == k + 1) {
    if (cur != ful && lowbit(cur ^ ful) != cur + 1) {
      cout << "REJECTED\n";
      exit(0);
    }
    return;
  }
  long long go = popcnt(cur & f[dep][q[dep]]);
  cur &= (~f[dep][q[dep]]);
  for (long long j = go; j <= go + popcnt(siz[dep]); j++) {
    dfs(dep + 1, cur | f[dep][j]);
  }
}
signed main() {
  cin >> n >> k;
  ful = (1LL << n) - 1;
  if (n == 1) {
    cout << "ACCEPTED\n";
    return 0;
  }
  for (long long i = 1; i <= k; i++) {
    q[i] = read();
    long long tmp = 0;
    for (long long j = 1; j <= q[i]; j++)
      f[i][j] = f[i][j - 1] | (1LL << (read() - 1));
    tmp = f[i][q[i]];
    siz[i] = (st[i - 1] ^ ful) & tmp;
    st[i] = st[i - 1] | tmp;
  }
  dfs(1, 0);
  if (popcnt(st[k]) != n) {
    cout << "REJECTED\n";
    return 0;
  }
  cout << "ACCEPTED\n";
  return 0;
}
