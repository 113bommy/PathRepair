#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  long long N, M, K;
  cin >> N >> M >> K;
  long long curRow = 0;
  long long curCol = 0;
  if (K < N) {
    printf("%lld 1", K + 1);
  } else {
    curRow = N - (K - N) / (M - 1);
    long long temp = (K - N) % (M - 1);
    if (curRow % 2 == 0) {
      curCol = 1 + temp;
    } else
      curCol = M - temp;
    printf("%lld %lld", curRow, curCol);
  }
}
