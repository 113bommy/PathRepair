#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, N, *m, M;
  cin >> n >> N;
  M = n % N;
  m = new int[N];
  for (int i = 0; i < N; i++) {
    if (i < N - M)
      cout << n / N + 1 << ' ';
    else
      cout << n / N << ' ';
  }
  return 0;
}
