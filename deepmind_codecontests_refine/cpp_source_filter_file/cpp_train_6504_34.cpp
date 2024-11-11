#include <bits/stdc++.h>
using namespace std;
int get_max[2000], a[2000];
void solve() {
  memset(get_max, 0, sizeof(get_max));
  int N;
  scanf("%d", &N);
  N++;
  for (int i = 2; i <= (1 << N) - 1; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = (1 << (N - 1)); i <= (1 << N) - 1; i++) {
    for (int j = i; j > 0; j /= 2) {
      get_max[j / 2] = max(get_max[j / 2], get_max[j] + a[j]);
    }
  }
  int answer = 0;
  for (int i = 1; i < (1 << (N - 1)); i++) {
    answer += (get_max[i] - min(get_max[i * 2] + a[i * 2],
                                get_max[i * 2 + 1] + a[i * 2 + 1]));
  }
  printf("%d\n", answer);
}
int main() {
  solve();
  return 0;
}
