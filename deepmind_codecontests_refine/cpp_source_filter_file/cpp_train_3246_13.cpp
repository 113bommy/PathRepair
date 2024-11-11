#include <bits/stdc++.h>
using namespace std;
int N, M, arr[1000] = {0}, num = 0, cnt = 0;
int main() {
  int a;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    arr[a]++;
  }
  for (int i = 1; i <= M; i++) {
    if (arr[i] != 0 && arr[i] % 2 == 0) {
      num += arr[i];
      cnt += arr[i] / 2;
    }
    if (arr[i] != 0 && arr[i] % 2 == 1) {
      num += arr[i] - 1;
      cnt += (arr[i] - 1) / 2;
    }
  }
  if (N % 2 == 0)
    num += (N / 2 - cnt);
  else if (N % 2 != 0)
    num += ((N + 1) / 2 - cnt);
  printf("%d\n", num);
}
