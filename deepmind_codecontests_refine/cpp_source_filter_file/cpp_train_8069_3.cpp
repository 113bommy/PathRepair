#include <bits/stdc++.h>
using namespace std;
const int Buffer_Size = 1 << 10;
char buffer[Buffer_Size], *ihead = buffer + Buffer_Size, *itail = ihead;
char Next_Char() {
  if (ihead == itail) fread(buffer, 1, Buffer_Size, stdin), ihead = buffer;
  return *ihead++;
}
template <typename T>
void read(T &n) {
  n = 0;
  char ch = Next_Char();
  while (!isdigit(ch)) ch = Next_Char();
  while (isdigit(ch)) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = Next_Char();
  }
}
long long r, c, n, k, tp, sum;
long long a[3002], cnt[3002], L[3002], R[3002];
vector<long long> v[3002];
struct Position {
  long long x, y;
} p[3002];
bool Cmp(long long x, long long y) { return p[x].y < p[y].y; }
bool DFS(long long x, long long step) {
  if (!step || !x) return 1;
  if (!DFS(L[x], step - 1))
    cnt[L[x]] = cnt[x];
  else
    cnt[L[x]] += cnt[x];
  return 0;
}
int main() {
  read(r), read(c), read(n), read(k);
  for (long long i = 1; i <= n; ++i) {
    read(p[i].x), read(p[i].y);
    v[p[i].x].push_back(i);
  }
  long long ans = 0;
  for (long long i = 1; i <= r; ++i) {
    tp = sum = 0;
    for (long long j = 1; j <= n; ++j)
      if (p[j].x >= i) a[++tp] = j;
    sort(a + 1, a + tp + 1, Cmp);
    a[tp + 1] = n + 1;
    memset(cnt, 0, sizeof(cnt));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    long long now = 0;
    for (long long j = 1; j <= c; ++j) {
      while (p[a[now + 1]].y == j && now < tp) {
        ++now;
        L[a[now]] = a[now - 1], R[a[now]] = a[now + 1];
      }
      long long tmp = a[now];
      for (long long l = 1; l < k; ++l) tmp = L[tmp];
      ++cnt[tmp];
    }
    for (long long j = 1; j <= tp; ++j) sum += p[a[j]].y * cnt[a[j]];
    ans += sum;
    for (long long j = r; j >= i + 1; --j) {
      long long sz = (long long)v[j].size();
      for (long long l = 0; l < sz; ++l) {
        long long x = v[j][l], q = x;
        for (long long o = 1; o <= k; ++o) {
          sum -= (p[x].y - p[L[x]].y) * cnt[x];
          x = L[x];
          if (!x) break;
        }
        x = q;
        DFS(x, k);
        x = q;
        L[R[x]] = L[x], R[L[x]] = R[x];
      }
      ans += sum;
    }
  }
  printf("%d\n", ans);
  return 0;
}
