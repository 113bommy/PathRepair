#include <bits/stdc++.h>
using namespace std;
namespace runzhe2000 {
int f[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
void main() {
  int n;
  scanf("%d", &n);
  if (n <= 11)
    printf("%d\n", f[n]);
  else
    printf("%I64d\n", f[11] + (n - 11) * 49ll);
}
}  // namespace runzhe2000
int main() { runzhe2000::main(); }
