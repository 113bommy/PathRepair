#include <bits/stdc++.h>
using namespace std;
int N, M;
int main() {
  cin >> M >> N;
  if (M == N) {
    cout << N << '1' << ' ' << N << '2';
    return 0;
  }
  if (N - M == 1) {
    cout << M << '9' << ' ' << N << '0';
    return 0;
  }
  if (M == 9 && N == 1) {
    cout << "9 10";
    return 0;
  }
  cout << -1;
}
