#include <bits/stdc++.h>
using namespace std;
const int maxn = 300050;
struct Node {
  long long num;
  int id;
} c[maxn];
bool cmp(Node a, Node b) { return a.num > b.num; }
long long tot = 0, tot2 = 0;
int res[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &c[i].num);
    tot += (long long)i * c[i].num;
    c[i].id = i;
  }
  sort(c + 1, c + 1 + n, cmp);
  set<int> nm;
  for (int i = k + 1; i <= k + n; i++) nm.insert(i);
  set<int>::iterator it;
  for (int i = 1; i <= n; i++) {
    it = nm.lower_bound(c[i].id);
    tot2 += (long long)(*it) * c[i].num;
    res[c[i].id] = *it;
    nm.erase(*it);
  }
  printf("%I64d\n", tot2 - tot);
  for (int i = 1; i <= n; i++) printf("%d%c", res[i], i == n ? '\n' : ' ');
  return 0;
}
