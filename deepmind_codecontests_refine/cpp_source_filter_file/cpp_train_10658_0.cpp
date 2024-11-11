#include <bits/stdc++.h>
using namespace std;
double tux, foo, bar, baz, quz = 1, pur;
int main() {
  scanf("%lf", &tux);
  for (int i = 1; i <= tux; i++) {
    scanf("%lf", &pur);
    foo = foo + pur;
    bar + bar + 1;
    if (foo * quz > baz * bar) {
      baz = foo;
      quz = bar;
    }
  }
  printf("%.6lf", quz / baz);
  return 0;
}
