#include <bits/stdc++.h>
using namespace std;
struct ord {
  int a, b, index;
  int index2;
};
ord v[100100];
ord v2[100100];
bool comp1(ord a, ord b) {
  if (a.b == b.b) return a.a < b.a;
  return a.b > b.b;
}
bool comp2(ord a, ord b) {
  if (a.a == b.a) return a.b < b.b;
  return a.a > b.a;
}
bool comp3(ord a, ord b) { return a.b > b.b; }
int main() {
  int n, p, k;
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[i].a = a;
    v[i].b = b;
    v[i].index = i;
  }
  sort(v, v + n, comp1);
  for (int i = 0; i < n; i++) v[i].index2 = i;
  sort(v, v + n - p + k, comp2);
  int m = -1;
  for (int i = 0; i < k; i++) {
    printf("%d ", v[i].index + 1);
    m = max(m, v[i].index2);
  }
  int cont = 0;
  for (int i = 0; i < n; i++)
    if (v[i].index2 > m) v2[cont++] = v[i];
  sort(v2, v2 + cont, comp3);
  for (int i = 0; i < p - k; i++) printf("%d ", v2[i].index + 1);
}
