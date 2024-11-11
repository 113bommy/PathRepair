#include <bits/stdc++.h>
using namespace std;
int n;
int a[2005];
int prob[5005];
int suffix[10010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      prob[a[i] - a[j]]++;
    }
  }
  for (int i = 4999; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + prob[i];
  }
  double answer = 0;
  for (int i = 0; i < 5000; i++) {
    for (int j = 0; j < 5000; j++) {
      answer += 1.0 * prob[i] * prob[j] * suffix[i + j + 1];
    }
  }
  double nc2 = (n) * (n - 1) / 2;
  answer /= (nc2 * nc2 * nc2);
  printf("%.10f\n", answer);
  return 0;
}
