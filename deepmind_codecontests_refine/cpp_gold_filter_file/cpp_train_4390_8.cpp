#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int arr[350];
long long int num_of_div(long long int x) {
  int res = 0;
  long long int i;
  for (i = 2; i * i < x; i++) {
    if (x % i == 0) res += 2;
  }
  if (i * i == x) res++;
  return res;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", arr + i);
    }
    sort(arr, arr + N);
    if (N == 1) {
      long long int g = 1LL * arr[0] * arr[0];
      if (N == num_of_div(g))
        printf("%lld\n", g);
      else
        puts("-1");
    } else {
      long long int g = 1LL * arr[0] * arr[N - 1];
      bool flag = false;
      for (int i = 1; i < (N + 1) / 2; i++) {
        if (1LL * arr[i] * arr[N - i - 1] != g) {
          flag = true;
          break;
        }
      }
      if (flag || num_of_div(g) != N)
        puts("-1");
      else
        printf("%lld\n", g);
    }
  }
}
