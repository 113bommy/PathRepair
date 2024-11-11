#include <bits/stdc++.h>
using namespace std;
long long K, B, N, T;
int main() {
  cin >> K >> B >> N >> T;
  if (K == 1 && 1 + N * B >= T) {
    cout << (int)ceil((1 + N * B - T) / (1.0 * B)) << endl;
    return 0;
  }
  if (K == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long C = 1, counter = N + 1;
  double thres = 1.0 * (T * (K - 1) + B) / (K - 1 + B);
  for (int i = 1; i <= N; i++) {
    C *= K;
    if (C > thres) {
      counter = i;
      break;
    }
  }
  counter--;
  cout << N - counter << endl;
  return 0;
}
