#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
int ch[maxn];
int a[maxn], n, p[maxn];
long long ans[maxn], sum[maxn];
void add(int x, int v) {
  for (int i = x; i <= n; i += i & (-i)) ch[i] += v;
}
int query(int x) {
  int sum = 0;
  for (int i = x; i; i -= i & (-i)) sum += ch[i];
  return sum;
}
void add_sum(int x, int v) {
  for (int i = x; i <= n; i += i & (-i)) sum[i] += v;
}
int query_sum(int x) {
  long long res = 0;
  for (int i = x; i; i -= i & (-i)) res += sum[i];
  return res;
}
int cal(int n, int x) {
  int t = query(x);
  return min(t, n - t);
}
int find(int k) {
  k--;
  int x = 0;
  for (int i = 20; i >= 0; i--)
    if (x + (1 << i) <= n && ch[x + (1 << i)] <= k) {
      x += 1 << i;
      k -= ch[x];
    }
  return x + 1;
}
inline long long ari(int n) { return 1ll * n * (n + 1) / 2; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    int x = p[i];
    ans[i] = ans[i - 1] + (i - 1 - query(x));
    add(x, 1);
  }
  memset(ch, 0, sizeof(ch));
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = p[i];
    add(x, 1);
    add_sum(x, x);
    sum += x;
    int k = (i + 1) / 2;
    long long c = find(k);
    long long tmp = query_sum(c);
    long long a = k * c - tmp - ari(k - 1);
    long long b = (sum - tmp) - (i - k) * c - ari(i - k);
    ans[i] += a + b;
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
