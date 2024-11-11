#include <bits/stdc++.h>
using namespace std;
int main() {
  long long Q, i, N, A, B;
  cin >> Q;
  for (i = 0; i < Q; i++) {
    cin >> N >> A >> B;
    double cpb = B / 2;
    if (A <= cpb)
      cout << A * N << endl;
    else if (N % 2)
      cout << B * (N / 2) + A << endl;
    else
      cout << B * (N / 2);
  }
  return 0;
}
