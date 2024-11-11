#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 100000 + 10;
long long a[maxn];
long long n;
struct node {
  int num, pos;
} b[maxn];
int cmp(node p, node q) {
  if (p.num == q.num)
    return p.pos < q.pos;
  else
    return p.num < q.num;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int x;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      b[i].num = x;
      b[i].pos = i;
    }
    sort(b, b + n, cmp);
    int k;
    k = b[0].num;
    a[b[0].pos] = b[0].num;
    for (int i = 1; i < n; i++) {
      if (b[i].num == k) {
        a[b[i].pos] = k + 1;
        k++;
      } else {
        a[b[i].pos] = b[i].num;
        k = b[i].num;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
