#include <bits/stdc++.h>
using namespace std;
bitset<1010> possible;
bitset<1010> rob;
int a;
int main() {
  int n, r;
  scanf("%d", &n);
  possible.set();
  for (int p = 0; p < n; p++) {
    scanf("%d", &r);
    rob.reset();
    for (int i = 0; i < r; i++) {
      scanf("%d", &a);
      rob[a] = 1;
    }
    possible &= rob;
  }
  for (int i = 1; i < 101; i++)
    if (possible[i]) printf("%d ", i);
  printf("\n");
}
