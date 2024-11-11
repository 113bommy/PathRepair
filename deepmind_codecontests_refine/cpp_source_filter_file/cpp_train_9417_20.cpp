#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
int prox[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++) {
    int first;
    scanf("%d", &first);
    prox[first] = first;
  }
  for (int(i) = (1); (i) < (N); (i)++) prox[i] = max(prox[i], prox[i - 1]);
  int ans = 0;
  for (int(i) = (2); (i) < (N); (i)++)
    if (prox[i] == i)
      for (int j = i + i; j < N; j += i) {
        ans = max(ans, prox[j - 1] % i);
      }
  printf("%d\n", ans);
}
