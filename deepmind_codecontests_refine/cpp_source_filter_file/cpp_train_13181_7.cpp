#include <bits/stdc++.h>
using namespace std;
int n, C[16], K;
int main() {
  int i, j, a;
  scanf("%d%d", &n, &K);
  for (i = 0; i < n; i++) {
    int s = 0;
    for (j = 0; j < K; j++) {
      scanf("%d", &a);
      s += (a << j);
    }
    if (s == 0) {
      puts("YES");
      return 0;
    }
    C[s]++;
  }
  for (int i = 0; i < (a << K); i++) {
    for (int j = 0; j < (a << K); j++) {
      if (i & j) continue;
      if (C[i] != 0 && C[j] != 0) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
