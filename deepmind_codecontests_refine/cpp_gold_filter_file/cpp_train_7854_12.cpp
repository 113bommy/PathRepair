#include <bits/stdc++.h>
using namespace std;
struct sss {
  int a, b;
} exam[5100];
int n;
bool cmp(sss x, sss y) { return x.a == y.a ? x.b < y.b : x.a < y.a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &exam[i].a, &exam[i].b);
  sort(exam + 1, exam + 1 + n, cmp);
  int nowdate = 0;
  for (int i = 1; i <= n; ++i) {
    if (exam[i].b >= nowdate)
      nowdate = exam[i].b;
    else if (exam[i].a > nowdate)
      nowdate = exam[i].a;
  }
  printf("%d\n", nowdate);
}
