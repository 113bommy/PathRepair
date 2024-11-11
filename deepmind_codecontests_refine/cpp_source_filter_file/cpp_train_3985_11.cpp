#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
long long pre[200005];
long long m, n, s, v, mpgeshu, zongbianshu, ssbb;
struct sb {
  long long x, y, z;
} mp[200100];
bool cmp(sb sb1, sb sb2) { return sb1.z > sb2.z; }
long long find(long long x) {
  if (pre[x] == x) return x;
  pre[x] = find(pre[x]);
  return pre[x];
}
int main() {
  mpgeshu = 1;
  ssbb = 0;
  scanf("%lld %lld", &m, &n);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long j = 1; j <= n; j++) {
    scanf("%lld", &b[j]);
  }
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &s);
    for (long long j = 1; j <= s; j++) {
      scanf("%lld", &v);
      ssbb = ssbb + a[i] + b[v];
      mp[mpgeshu].x = n + i;
      mp[mpgeshu].y = v;
      mp[mpgeshu].z = a[i] + b[v];
      mpgeshu++;
    }
  }
  for (long long i = 1; i <= n * 2; i++) {
    pre[i] = i;
  }
  sort(mp + 1, mp + mpgeshu, cmp);
  for (long long i = 1; i <= mpgeshu - 1; i++) {
    if (zongbianshu == n + m - 1) break;
    long long ss = find(mp[i].x);
    long long bb = find(mp[i].y);
    if (ss != bb) {
      pre[find(ss)] = find(bb);
      ssbb = ssbb - mp[i].z;
      zongbianshu++;
    }
  }
  printf("%lld\n", ssbb);
}
