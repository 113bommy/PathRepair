#include <bits/stdc++.h>
using namespace std;
struct rev {
  int a, b, id, tag;
} r[100005];
bool cmp1(rev x, rev y) {
  if (x.a == y.a) {
    return x.b > y.b;
  }
  return x.a > y.a;
}
bool cmp2(rev x, rev y) {
  if (x.b != y.b) return x.b < y.b;
  if (x.a != y.a) return x.a > y.a;
  return x.tag < y.tag;
}
int main() {
  long long n, k, p;
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> r[i].a >> r[i].b;
    r[i].id = i;
  }
  sort(r + 1, r + n + 1, cmp2);
  for (int i = 1; i < p - k; i++) {
    r[i].tag = 1;
  }
  sort(r + 1, r + n + 1, cmp1);
  for (int i = 1, cnt = 0; cnt < k; i++) {
    if (r[i].tag != 1) {
      cnt++;
      r[i].tag = 2;
      printf("%d ", r[i].id);
    }
  }
  sort(r + 1, r + n + 1, cmp2);
  for (int i = n, cnt = 0, num = 0; cnt < p - k; i--) {
    if (num >= k) {
      printf("%d ", r[i].id);
      cnt++;
    }
    if (r[i].tag == 2) num++;
  }
}
