#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1608864")
template <typename T>
T abs(T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
T sqr(T a) {
  return (a) * (a);
}
template <typename T>
int size(T& a) {
  return (int)((a).size());
}
void initf() {}
int main() {
  initf();
  int test, n, k;
  scanf("%d", &test);
  for (int i = 0; i < test; ++i) {
    scanf("%d", &n);
    printf("%d\n", max(0, n - 2));
  }
  return 0;
}
