#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
int main() {
  int k;
  cin >> k;
  if (k > 36)
    puts("-1");
  else {
    int ans = k / 2;
    int zero = k % 2;
    for (int i = 1; i <= ans; i++) {
      printf("8");
    }
    for (int i = 1; i <= zero; i++) {
      printf("6");
    }
    printf("\n");
  }
  return 0;
}
