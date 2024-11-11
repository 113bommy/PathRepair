#include <bits/stdc++.h>
using namespace std;
bool isprime[3001];
int div_arr[3001] = {0};
int main() {
  for (int i = 2; i * i < 3001; i++) {
    if (!isprime[i]) {
      for (int j = 2 * i; j < 3001; j += i) {
        isprime[j] = 1;
        div_arr[j]++;
      }
    }
  }
  int N;
  scanf("%d", &N);
  int ret = 0;
  for (int i = 1; i <= N; i++)
    if (div_arr[i] == 2) ret++;
  printf("%d\n", ret);
  return 0;
}
