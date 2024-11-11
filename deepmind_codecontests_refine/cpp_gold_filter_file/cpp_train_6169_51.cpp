#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int main() {
  int t;
  scanf("%d", &t);
  for (int cs = 1; cs <= t; cs++) {
    int n;
    scanf("%d", &n);
    if (n % 4)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
