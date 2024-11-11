#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000000000000;
char a[105];
int nb, ns, nc, pb, ps, pc;
long long r;
map<char, int> p;
long long judge(long long x) {
  long long sum = 0;
  if (x * p['B'] - nb > 0) sum += (x * p['B'] - nb) * pb;
  if (x * p['S'] - ns > 0) sum += (x * p['S'] - ns) * ps;
  if (x * p['C'] - nc > 0) sum += (x * p['C'] - nc) * pc;
  return sum;
}
int main() {
  while (~scanf("%s", a)) {
    p.clear();
    scanf("%d%d%d", &nb, &ns, &nc);
    scanf("%d%d%d", &pb, &ps, &pc);
    scanf("%I64d", &r);
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
      p[a[i]]++;
    }
    long long low = 0, high = maxn;
    while (low < high) {
      long long mid = (low + high) >> 1;
      if (judge(mid) > r)
        high = mid;
      else
        low = mid + 1;
    }
    while (judge(low) > r) low--;
    printf("%I64d\n", low);
  }
  return 0;
}
