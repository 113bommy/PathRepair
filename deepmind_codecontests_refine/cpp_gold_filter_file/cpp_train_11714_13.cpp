#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(int argc, char const* argv[]) {
  int d, l, v1, v2;
  scanf("%d%d%d%d", &d, &l, &v1, &v2);
  printf("%lf\n", double((double(l - d)) / (double(v1 + v2))));
  return 0;
}
