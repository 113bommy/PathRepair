#include <bits/stdc++.h>
using namespace std;
const char FI[] = "fruits.i1";
const char FO[] = "fruits.o1";
const int MAXN = 100005;
struct Fruit {
  int a, o, id;
};
Fruit p[MAXN];
int n, test;
long long sum;
bool cmp(Fruit x, Fruit y) { return x.a > y.a; }
int main() {
  scanf("%d", &test);
  for (int t = 0; t < test; t++) {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i++) {
      scanf("%d%d", &p[i].a, &p[i].o);
      p[i].id = i;
    }
    sort(p + 1, p + 2 * n - 1, cmp);
    sum = 0;
    for (int i = 1; i < n; i++) sum += (p[2 * i].o - p[2 * i + 1].o);
    printf("YES\n");
    printf("%d ", p[1].id);
    int i = (sum > 0 ? 2 : 3);
    while (i <= 2 * n - 1) {
      printf("%d ", p[i].id);
      i += 2;
    }
    printf("\n");
  }
  return 0;
}
