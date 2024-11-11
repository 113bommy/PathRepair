#include <bits/stdc++.h>
using namespace std;
int sieve[1010];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> questions;
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) continue;
    int k = i;
    while (k <= n) {
      ++ans;
      questions.push_back(k);
      k *= i;
    }
    for (int j = i * i; j <= n; ++j) {
      sieve[j] = 1;
    }
  }
  printf("%d\n", ans);
  for (int x : questions) {
    printf("%d ", x);
  }
  return 0;
}
