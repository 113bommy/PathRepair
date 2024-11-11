#include <bits/stdc++.h>
using namespace std;
const int N = 5000005;
int d[N];
int a, b, t;
int main() {
  for (int i = 2; i < N; ++i) {
    d[i] = 1;
  }
  for (int i = 2; i < N; ++i) {
    if (d[i] == 1) {
      for (int j = i * 2; j < N; j += i) {
        int first = j;
        while (first % i == 0) {
          ++d[j];
          first /= i;
        }
      }
    }
  }
  for (int i = 2; i < N; ++i) {
    if (d[i] > 1) --d[i];
    d[i] += d[i - 1];
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", d[a] - d[b]);
  }
}
