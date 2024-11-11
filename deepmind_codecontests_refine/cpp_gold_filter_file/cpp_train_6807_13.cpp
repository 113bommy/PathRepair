#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
using namespace std;
int main() {
  int n;
  scanf("%d", &(n));
  vector<int> v1(n), v2(n), v3(n);
  if (!(n % 2)) {
    printf("-1\n");
    return 0;
  }
  for (int i = (0), endi = (n); i < endi; ++i) v1[i] = i;
  for (int i = (0), endi = (n); i < endi; ++i) v2[i] = (i + 1) % n;
  for (int i = (0), endi = (n); i < endi; ++i) v3[i] = (v1[i] + v2[i]) % n;
  for (int i = (0), endi = ((v1).size()); i < endi; ++i) {
    printf("%d ", (v1[i]));
  };
  printf("\n");
  for (int i = (0), endi = ((v2).size()); i < endi; ++i) {
    printf("%d ", (v2[i]));
  };
  printf("\n");
  for (int i = (0), endi = ((v3).size()); i < endi; ++i) {
    printf("%d ", (v3[i]));
  };
  printf("\n");
}
