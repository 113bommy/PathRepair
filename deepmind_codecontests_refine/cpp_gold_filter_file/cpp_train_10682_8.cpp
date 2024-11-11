#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K, T;
  cin >> N >> K >> T;
  if (T >= K && T <= N)
    cout << K << "\n";
  else {
    if (T > N)
      cout << N + K - T << "\n";
    else
      cout << T << "\n";
  }
  return 0;
}
