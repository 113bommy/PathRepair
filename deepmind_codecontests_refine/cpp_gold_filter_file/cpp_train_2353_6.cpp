#include <bits/stdc++.h>
using namespace std;
int N, K, Q, counter[200005], admissible[200005];
int main() {
  scanf("%d %d %d", &N, &K, &Q);
  for (int l, r, i = 0; i < N; i++) {
    scanf("%d %d", &l, &r);
    counter[l]++;
    counter[r + 1]--;
  }
  for (int i = 1; i <= 200000; i++) counter[i] += counter[i - 1];
  for (int i = 1; i <= 200000; i++) {
    if (counter[i] >= K) admissible[i] = 1;
    admissible[i] += admissible[i - 1];
  }
  for (int a, b, i = 0; i < Q; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", admissible[b] - admissible[a - 1]);
  }
  return 0;
}
