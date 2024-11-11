#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b;
} a[303000];
bool cmp(Node a, Node b) { return a.a < b.a; }
bool cmp1(Node a, Node b) { return a.b < b.b; }
int b[303000];
int main() {
  int n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i].a;
  for (long long i = 1; i <= n; i++) a[i].b = i;
  a[++n].a = 2000000000;
  a[n].b = n;
  sort(a + 1, a + 1 + n, cmp);
  int tail = 0, head = 0;
  for (long long i = 2; i <= n; i++) {
    if (a[i].a == a[i - 1].a) b[++tail] = i;
    if (a[i].a != a[i - 1].a) {
      int k = min(tail - head, a[i].a - a[i - 1].a - 1);
      for (long long j = 1; j <= k; j++) a[b[++head]].a = a[i - 1].a + j;
    }
  }
  sort(a + 1, a + 1 + n, cmp1);
  n--;
  for (long long i = 1; i <= n - 1; i++) printf("%d ", a[i].a);
  printf("%d\n", a[n].a);
  return 0;
}
