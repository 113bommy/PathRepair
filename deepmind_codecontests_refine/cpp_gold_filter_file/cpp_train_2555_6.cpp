#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const long long SZ = 210, SSZ = 0, APB = 26, one = 93, INF = 0x7FFFFFF,
                mod = 1000000007;
long long n, m, cnt, mk[SZ], fail[SZ];
long long arr[SZ], nex[SZ][APB];
long long src[SZ][SZ];
char ch[SZ];
void add(long long pos) {
  long long cur = 0;
  for (long long i = 1; ch[i]; ++i) {
    long long c = ch[i] - 'a';
    if (!nex[cur][c]) nex[cur][c] = ++cnt;
    cur = nex[cur][c];
  }
  mk[cur] += arr[pos];
}
void build() {
  queue<long long> q;
  q.push(0);
  for (; q.size();) {
    long long fr = q.front();
    q.pop();
    for (long long i = 0; i < APB; ++i) {
      long long t = nex[fr][i];
      if (t) {
        if (!fr)
          fail[t] = 0;
        else {
          long long u = fail[fr];
          for (; u && !nex[u][i]; u = fail[u])
            ;
          u = nex[u][i];
          fail[t] = u;
          mk[t] += mk[u];
        }
        q.push(t);
      }
    }
  }
}
long long get_nex(long long x, long long c) {
  for (; x && !nex[x][c]; x = fail[x])
    ;
  return nex[x][c];
}
void mul(long long dst[][SZ], long long x[][SZ], long long y[][SZ]) {
  long long res[SZ][SZ];
  memset(res, -63, sizeof(res));
  for (long long i = 0; i <= cnt; ++i) {
    for (long long j = 0; j <= cnt; ++j) {
      for (long long k = 0; k <= cnt; ++k) {
        res[i][j] = max(res[i][j], x[i][k] + y[k][j]);
      }
    }
  }
  memcpy(dst, res, sizeof(res));
}
void pow_mod(long long x) {
  long long ele[SZ][SZ], res[SZ][SZ];
  memcpy(ele, src, sizeof(ele));
  memset(res, -63, sizeof(res));
  for (long long i = 0; i <= cnt; ++i) res[i][i] = 0;
  for (; x; x /= 2) {
    if (x & 1) mul(res, res, ele);
    mul(ele, ele, ele);
  }
  memcpy(src, res, sizeof(res));
}
void init() {
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) cin >> arr[i];
  for (long long i = 1; i <= n; ++i) {
    cin >> ch + 1;
    add(i);
  }
  build();
  memset(src, -63, sizeof(src));
  for (long long i = 0; i <= cnt; ++i) {
    for (long long j = 0; j < APB; ++j) {
      long long tmp = get_nex(i, j);
      src[tmp][i] = mk[tmp];
    }
  }
  pow_mod(m);
  long long res = 0;
  for (long long i = 0; i <= cnt; ++i) {
    res = max(res, src[i][0]);
  }
  cout << res << endl;
}
void work() {}
int main() {
  std::ios::sync_with_stdio(0);
  long long casenum;
  {
    init();
    work();
  }
  return 0;
}
