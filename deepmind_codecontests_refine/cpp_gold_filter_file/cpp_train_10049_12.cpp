#include <bits/stdc++.h>
using namespace std;
long long N, K;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  K = min(N / 2, K);
  N -= 2 * K;
  cout << 2 * K * (K + N) - K << '\n';
}
