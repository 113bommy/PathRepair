#include <bits/stdc++.h>
using namespace std;
int A[111111], N;
long long cnt[20];
int main() {
  scanf("%d", &N);
  for (int q = 0; q < N; q++) {
    scanf("%d", &A[q]);
    cnt[A[q] + 10]++;
  }
  long long ret = cnt[10] * (cnt[10] - 1) / 2;
  for (int q = 1; q <= 10; q++) {
    ret += cnt[10 - q] * cnt[q + 10];
  }
  cout << ret << endl;
  return 0;
}
