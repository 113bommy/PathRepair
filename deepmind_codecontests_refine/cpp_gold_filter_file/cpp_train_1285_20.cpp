#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long K, B, N, T;
  cin >> K >> B >> N >> T;
  long long X = 1;
  for (int i = 1; i <= N; i++) {
    if (X * K + B > T) {
      cout << N - i + 1 << "\n";
      return 0;
    }
    X *= K;
    X += B;
  }
  cout << 0 << endl;
}
