#include <bits/stdc++.h>
using namespace std;
long long N, K;
bool has_bullet(long long slot) {
  if (2 * K >= N) return !(slot % 2 == 0 && slot < 2 * (N - K));
  if (N % 2 == 0) return (slot % 2 == 1 && slot + 2 * K - 1 >= N);
  if (slot == N - 1 && K > 0) return true;
  return (slot % 2 == 1 && slot + 2 * (K - 1) >= N);
}
int main() {
  int P;
  cin >> N >> K >> P;
  for (int i = 0; i < P; i++) {
    long long x;
    cin >> x;
    cout << (has_bullet(x - 1) ? 'X' : '.');
  }
  cout << '\n';
}
