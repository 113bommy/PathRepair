#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 9;
struct node {
  int m, p;
} a[N];
int last[N];
bool cmp(node a, node b) {
  if (a.m != b.m) return a.m < b.m;
  return a.p < b.p;
}
int main() {
  int T;
  scanf("%d", &T);
  priority_queue<int, vector<int>, greater<int>> PQ;
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = (0); i < (n); i++) scanf("%d%d", &a[i].m, &a[i].p);
    while (!PQ.empty()) PQ.pop();
    int tot = 0;
    long long ans = 0;
    sort(a, a + n, cmp);
    for (int i = (n)-1; i >= (0); i--) {
      if (a[i].m > i + tot) {
        int sz = PQ.size();
        if (a[i].m > i + tot + sz) {
          ans += a[i].p;
          tot++;
        } else {
          sz = a[i].m - i - tot;
          int cnt = 0;
          long long sum = 0;
          while (sz--) {
            last[cnt] = PQ.top();
            PQ.pop();
            sum += last[cnt++];
          }
          if (sum <= a[i].p) {
            tot += sz;
            ans += sum;
            PQ.push(a[i].p);
          } else {
            tot++;
            ans += a[i].p;
            for (int i = (0); i < (cnt); i++) PQ.push(i);
          }
        }
      } else {
        PQ.push(a[i].p);
      }
    }
    printf("%lld\n", ans);
  }
}
