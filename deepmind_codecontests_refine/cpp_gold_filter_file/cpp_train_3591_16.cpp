#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, M;
  cin >> N >> M;
  if (N == 1)
    puts("1");
  else if (M == 1)
    cout << M + 1 << endl;
  else if (M == N)
    cout << M - 1 << endl;
  else if (N % 2 == 1) {
    if (M > N / 2)
      cout << M - 1 << endl;
    else
      cout << M + 1 << endl;
  } else {
    if (M <= N / 2)
      cout << M + 1 << endl;
    else
      cout << M - 1 << endl;
  }
  return 0;
}
