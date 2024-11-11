#include <bits/stdc++.h>
using namespace std;
int N, M;
long long a[10001];
struct Q {
  int d, len;
  long long c;
  int s[31];
  int ans;
} q[30001];
int ind[30001];
bool Cmp(const int &i, const int &j) { return q[i].d < q[j].d; }
int _mod[] = {9699690, 31367009, 6319667, 21182921, 56606581};
int prime[25] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
bool Test(int *s, int len, int d) {
  int test = 0;
  for (int i = 0; i < len && test < N; i++)
    test = test * d + (s[i] == d ? 0 : s[i]);
  return test < N;
}
void Init() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%I64d", a + i);
  scanf("%d", &M);
  char ch[31];
  for (int i = 0; i < M; i++) {
    memset(ch, 0, sizeof(ch));
    scanf("%d%s%I64d", &q[i].d, ch, &q[i].c);
    q[i].len = 0;
    for (int j = 0; ch[j]; j++) {
      if ('0' <= ch[j] && ch[j] <= '9')
        q[i].s[j] = ch[j] - '0';
      else if (ch[j] != '?')
        q[i].s[j] = ch[j] - 'A' + 10;
      else
        q[i].s[j] = q[i].d;
      q[i].len++;
    }
    q[i].ans = 0;
    ind[i] = i;
    if (!Test(q[i].s, q[i].len, q[i].d)) {
      q[i].ans = -2;
      continue;
    }
    int l = q[i].len;
    for (int j = 0; j < q[i].len; j++) {
      if (!q[i].s[j]) {
        l--;
        continue;
      }
      if (q[i].s[j] != q[i].d) break;
      q[i].s[j] = 1;
      if (Test(q[i].s, q[i].len, q[i].d)) {
        q[i].s[j] = q[i].d;
        break;
      }
      l--;
      q[i].s[j] = 0;
    }
    for (int j = 0; j < l; j++) q[i].s[j] = q[i].s[j + (q[i].len - l)];
    q[i].len = l;
  }
  sort(ind, ind + M, Cmp);
  q[M].d = -1;
  ind[M] = M;
}
int d, mod;
int mark[5000000 + 5], msign;
long long f[5000000 + 5];
long long DP(int *s, int len) {
  if (!Test(s, len, d)) return 1;
  int state = 0, tran = 0;
  for (int i = 0; i < len; i++) {
    tran = tran * d + s[i];
    state = state * (d + 1) + s[i];
  }
  long long &ret = f[state];
  if (mark[state] == msign) return ret;
  mark[state] = msign;
  bool flag = 1;
  ret = 1;
  for (int i = 0; i < len; i++)
    if (s[i] == d) {
      for (int j = 0; j < d; j++) {
        s[i] = j;
        ret *= DP(s, len);
        ret %= mod;
      }
      flag = 0;
      s[i] = d;
      break;
    }
  if (flag) ret = a[tran] % mod;
  return ret;
}
void Solve() {
  int lb = 0, rb;
  memset(mark, -1, sizeof(mark));
  msign = 0;
  for (d = 2; d <= 16 && lb < M; d++) {
    for (rb = lb; q[ind[rb]].d == d; rb++)
      ;
    for (int i = lb; i < rb; i++)
      if (q[ind[i]].ans == -2) {
        for (int j = 0; j < 25; j++)
          if (!(q[ind[i]].c % prime[j])) {
            q[ind[i]].ans = prime[j];
            break;
          }
      }
    msign++;
    mod = 9699690;
    for (int i = lb; i < rb; i++)
      if (!q[ind[i]].ans) {
        long long ret = DP(q[ind[i]].s, q[ind[i]].len) + (q[ind[i]].c) % mod;
        if (!(ret % 2)) {
          q[ind[i]].ans = 2;
          continue;
        }
        if (!(ret % 3)) {
          q[ind[i]].ans = 3;
          continue;
        }
        if (!(ret % 5)) {
          q[ind[i]].ans = 5;
          continue;
        }
        if (!(ret % 7)) {
          q[ind[i]].ans = 7;
          continue;
        }
        if (!(ret % 11)) {
          q[ind[i]].ans = 11;
          continue;
        }
        if (!(ret % 13)) {
          q[ind[i]].ans = 13;
          continue;
        }
        if (!(ret % 17)) {
          q[ind[i]].ans = 17;
          continue;
        }
        if (!(ret % 19)) {
          q[ind[i]].ans = 19;
          continue;
        }
      }
    msign++;
    mod = 31367009;
    for (int i = lb; i < rb; i++)
      if (!q[ind[i]].ans) {
        long long ret = DP(q[ind[i]].s, q[ind[i]].len) + (q[ind[i]].c) % mod;
        if (!(ret % 23)) {
          q[ind[i]].ans = 23;
          continue;
        }
        if (!(ret % 29)) {
          q[ind[i]].ans = 29;
          continue;
        }
        if (!(ret % 31)) {
          q[ind[i]].ans = 31;
          continue;
        }
        if (!(ret % 37)) {
          q[ind[i]].ans = 37;
          continue;
        }
        if (!(ret % 41)) {
          q[ind[i]].ans = 41;
          continue;
        }
      }
    msign++;
    mod = 6319667;
    for (int i = lb; i < rb; i++)
      if (!q[ind[i]].ans) {
        long long ret = DP(q[ind[i]].s, q[ind[i]].len) + (q[ind[i]].c) % mod;
        if (!(ret % 43)) {
          q[ind[i]].ans = 43;
          continue;
        }
        if (!(ret % 47)) {
          q[ind[i]].ans = 47;
          continue;
        }
        if (!(ret % 53)) {
          q[ind[i]].ans = 53;
          continue;
        }
        if (!(ret % 59)) {
          q[ind[i]].ans = 59;
          continue;
        }
      }
    msign++;
    mod = 21182921;
    for (int i = lb; i < rb; i++)
      if (!q[ind[i]].ans) {
        long long ret = DP(q[ind[i]].s, q[ind[i]].len) + (q[ind[i]].c) % mod;
        if (!(ret % 61)) {
          q[ind[i]].ans = 61;
          continue;
        }
        if (!(ret % 67)) {
          q[ind[i]].ans = 67;
          continue;
        }
        if (!(ret % 71)) {
          q[ind[i]].ans = 71;
          continue;
        }
        if (!(ret % 73)) {
          q[ind[i]].ans = 73;
          continue;
        }
      }
    msign++;
    mod = 56606581;
    for (int i = lb; i < rb; i++)
      if (!q[ind[i]].ans) {
        long long ret = DP(q[ind[i]].s, q[ind[i]].len) + (q[ind[i]].c) % mod;
        if (!(ret % 79)) {
          q[ind[i]].ans = 79;
          continue;
        }
        if (!(ret % 83)) {
          q[ind[i]].ans = 83;
          continue;
        }
        if (!(ret % 89)) {
          q[ind[i]].ans = 89;
          continue;
        }
        if (!(ret % 97)) {
          q[ind[i]].ans = 97;
          continue;
        }
        q[ind[i]].ans = -1;
      }
    lb = rb;
  }
  for (int i = 0; i < M; i++) printf("%d\n", max(-1, q[i].ans));
}
int main() {
  Init();
  Solve();
  return 0;
}
