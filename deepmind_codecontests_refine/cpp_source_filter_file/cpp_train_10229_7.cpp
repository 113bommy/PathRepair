#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long int A, B, N, t = 0;
    cin >> A >> B >> N;
    if (B > A) swap(A, B);
    while (A <= N && B <= N) {
      if (t % 2 == 0)
        A += B;
      else
        B += A;
      t++;
    }
    cout << t << '\n';
  }
  return 0;
}
