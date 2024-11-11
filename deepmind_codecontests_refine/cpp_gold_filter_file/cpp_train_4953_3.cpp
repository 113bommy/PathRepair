#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << "-1\n";
    return 0;
  }
  if (K == 2 && N < 5) {
    cout << "-1\n";
    return 0;
  }
  if (K == 3 && N < 4) {
    cout << "-1\n";
    return 0;
  }
  if (K == 3) {
    cout << N - 1 << '\n';
    cout << "1 2\n";
    for (int i = 2; i < N; ++i) cout << i << ' ' << N << '\n';
    return 0;
  }
  if (K == 2) {
    cout << N - 1 << '\n';
    for (int i = 1; i < N; ++i) {
      cout << i << ' ' << i + 1 << '\n';
    }
    return 0;
  }
  cout << "-1\n";
  return 0;
}
