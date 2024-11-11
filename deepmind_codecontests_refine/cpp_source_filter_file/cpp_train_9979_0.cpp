#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, mod = 1e9 + 7;
  cin >> N;
  vector<int> V(N + 1);
  for (int i = 2; i <= N; i++) {
    int tmp = i;
    for (int j = 2; j <= N; j++) {
      while (tmp % j == 0) tmp /= j, V.at(i)++;
    }
  }
  long ans = 1;
  for (int i = 2; i < N + 1; i++) {
    if (V.at(i)) (ans *= V.at(i) + 1) %= mod;
  }
  cout << ans << "\n";
}
