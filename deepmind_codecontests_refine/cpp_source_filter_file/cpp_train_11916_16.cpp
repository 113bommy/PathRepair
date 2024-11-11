#include <bits/stdc++.h>
using namespace std;
int main() {
  long long SUM = 1, N, UM = 1e18, TUM = 1e17;
  cin >> N;
  for (int i = 0; i < 814; i++) {
    SUM += TUM;
    SUM %= N;
  }
  cout << (1 + (N - SUM)) << " " << (UM + (N - SUM)) << endl;
  return 0;
}
