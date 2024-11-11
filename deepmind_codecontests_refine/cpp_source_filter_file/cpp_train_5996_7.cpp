#include <bits/stdc++.h>
using namespace std;
int inf = (1e9) + 7;
int v[200005];
int eliminated[2000005];
int main() {
  int n, k;
  cin >> n >> k;
  memset(eliminated, 0, sizeof(eliminated));
  for (int i = 0; i < k; ++i) {
    scanf("%d", v + i);
    v[i] %= (n - i);
  }
  int leader = 0;
  for (int i = 0; i < k; ++i) {
    int c = leader;
    int k = 0;
    while (k < v[i]) {
      c = (c + 1) % n;
      if (!eliminated[c]) k++;
    }
    eliminated[c] = 1;
    printf("%d ", c + 1);
    while (eliminated[c + 1]) c = (c + 1) % n;
    leader = (c + 1) % n;
  }
  printf("\n");
}
