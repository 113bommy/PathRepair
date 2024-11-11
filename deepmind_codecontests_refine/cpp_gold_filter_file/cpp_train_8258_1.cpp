#include <bits/stdc++.h>
using namespace std;
struct node {
  long long k, b;
} qlist[100003];
bool operator<(const node &a, const node &b) {
  long long k[2], bb[2];
  k[0] = a.k;
  k[1] = b.k;
  bb[0] = a.b;
  bb[1] = b.b;
  if (k[0] < 0) {
    k[0] *= -1;
    bb[0] *= -1;
  }
  if (k[1] < 0) {
    k[1] *= -1;
    bb[1] *= -1;
  }
  return bb[0] * k[1] > k[0] * bb[1];
}
int main() {
  int i, n, j;
  long long ans = 0, last;
  scanf("%d", &n);
  for (j = 0, i = 0; i < n; i++, j++) {
    scanf("%I64d%I64d", &qlist[j].k, &qlist[j].b);
    if (qlist[j].k == 0) {
      j--;
      continue;
    }
    if (qlist[j].k < 0) ans += qlist[j].k;
  }
  int print = 0;
  n = j;
  sort(qlist, qlist + n);
  last = ans;
  for (i = 0; i < n; i++) {
    if (i > 0 && qlist[i].b * qlist[i - 1].k != qlist[i].k * qlist[i - 1].b) {
      if (last != ans) {
        if (last != ans) print++;
        last = ans;
      }
    }
    if (qlist[i].k > 0)
      ans += qlist[i].k;
    else
      ans -= qlist[i].k;
  }
  if (last != ans) {
    print++;
    last = ans;
  }
  printf("%d\n", print);
  return 0;
}
