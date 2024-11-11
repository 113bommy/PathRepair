#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int T, N;
int main(int argc, char** argv) {
  scanf("%d", &T);
  for (int t = (0); t < (T); t++) {
    int ans = 0;
    scanf("%d", &N);
    while (N > 1 && !(N % 3)) {
      if (!(N % 6))
        N /= 6;
      else
        N *= 2;
      ans++;
    }
    printf("%d\n", N == 1 ? ans : -1);
  }
  return 0;
}
