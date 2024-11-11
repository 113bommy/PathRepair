#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct node {
  long long a, b, c, idx;
  void slove() {
    long long mx = max(a, max(b, c));
    long long mn = min(a, min(b, c));
    long long e = 1LL * a + b + c - mx - mn;
    a = mx, b = e, c = mn;
  }
};
bool cmp(node x, node y) {
  if (x.a != y.a)
    return x.a < y.a;
  else if (x.b != y.b)
    return x.b < y.b;
  else {
    return x.c < y.c;
  }
}
node num[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &num[i].a, &num[i].b, &num[i].c);
    num[i].idx = i;
  }
  for (int i = 1; i <= n; i++) num[i].slove();
  sort(num + 1, num + n + 1, cmp);
  int now = 1;
  int nowi = 2;
  int mn = 0;
  int k1 = -1, k2 = -1;
  for (int i = 1; i <= n; i++) {
    if (num[i].c > mn) {
      mn = num[i].c;
      k1 = num[i].idx;
    }
  }
  num[n + 1].a = -1, num[n + 1].b = -1, num[n + 1].c = -1;
  while (nowi <= n + 1) {
    if (num[nowi].a != num[now].a || num[nowi].b != num[now].b) {
      if (nowi - now > 1) {
        if (num[nowi - 2].c + num[nowi - 1].c > mn && num[nowi - 1].a > mn &&
            num[nowi - 1].b > mn) {
          mn = min(num[nowi - 1].a,
                   min(num[nowi - 1].b, num[nowi - 1].c + num[nowi - 2].c));
          k1 = num[nowi - 1].idx;
          k2 = num[nowi - 2].idx;
        }
      }
      now = nowi;
      nowi++;
    } else {
      nowi++;
    }
  }
  if (k2 != -1) {
    cout << 2 << endl;
    cout << k1 << ' ' << k2 << endl;
  } else {
    cout << 1 << endl;
    cout << k1 << endl;
  }
  return 0;
}
