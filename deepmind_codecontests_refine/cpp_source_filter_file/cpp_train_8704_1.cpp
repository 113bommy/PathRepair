#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  while (cin >> N) {
    if (N < 10) {
      printf("YES\n");
      break;
    }
    while (N > 10 && N % 10 == 0) N /= 10;
    long long sum = 0;
    long long T = N;
    while (T) {
      sum = sum * 10 + T % 10;
      T /= 10;
    }
    if (sum == N)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
