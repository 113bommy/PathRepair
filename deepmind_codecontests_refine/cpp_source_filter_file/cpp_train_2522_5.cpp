#include <bits/stdc++.h>
using namespace std;
long long int Fun(long long int X, long long int *ar, long long int N) {
  long long int Sum = 0, C = 0, cnt = 1;
  for (int i = 2; i <= N; i++) {
    if (ar[i] == 1) cnt++;
    if (ar[i] == ar[i - 1] && ar[i] == 1) {
      Sum++;
      if (Sum + 1 >= X) C++;
    } else
      Sum = 0;
  }
  if (X == 1) C = cnt;
  return C;
}
int main() {
  long long int arr[40005], vec[40005];
  long long int N, M, K;
  cin >> N >> M >> K;
  for (long long int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  for (long long int i = 1; i <= M; i++) {
    cin >> vec[i];
  }
  long long int rt = sqrt(K), ans = 0;
  for (long long int i = 1; i <= rt; i++) {
    if (K % i == 0) {
      long long int x = i, y = K / i;
      int f1 = 0, f2 = 0;
      if (x <= N && y <= M) {
        ans += Fun(x, arr, N) * Fun(y, vec, M);
        f1 = 1;
      }
      if (x <= M && y <= N) {
        ans += Fun(y, arr, N) * Fun(x, vec, M);
        f2 = 1;
      }
      if (x == y && f1 == 1 && f2 == 1) {
        ans -= Fun(y, arr, N) * Fun(x, vec, M);
      }
    }
  }
  printf("%lld\n", ans);
}
