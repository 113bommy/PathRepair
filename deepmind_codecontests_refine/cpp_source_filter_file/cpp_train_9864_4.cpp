#include <bits/stdc++.h>
using namespace std;
set<int> s;
const int maxn = 1e5 + 5;
struct node {
  int power;
  int val;
  int id;
  long long sum;
};
node a[maxn];
bool cmp(node n1, node n2) { return n1.power < n2.power; }
bool cmp1(node n1, node n2) { return n1.id < n2.id; }
int main() {
  int n, k, i, j;
  long long ans;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].power);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
  }
  sort(a, a + n, cmp);
  ans = 0;
  for (i = 0; i < n; i++) {
    a[i].sum = ans + a[i].val;
    if (s.size() < k) {
      s.insert(a[i].val);
      ans += a[i].val;
    } else {
      if (s.empty()) continue;
      if ((*s.begin()) < a[i].val) {
        ans += (a[i].val - (*s.begin()));
        s.erase(s.begin());
        s.insert(a[i].val);
      }
    }
  }
  sort(a, a + n, cmp1);
  for (i = 0; i < n; i++) {
    printf("%lld", a[i].sum);
    if (i != n - 1)
      printf(" ");
    else
      printf("\n");
  }
}
