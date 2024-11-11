#include <bits/stdc++.h>
using namespace std;
long long UM = 1000000000000000000;
long long TUM = 100000000000000000;
int main() {
  long long SUM, N;
  cin >> N;
  SUM = 1;
  for (int i = 1; i <= 810; i++) {
    SUM += TUM;
    SUM %= N;
  }
  cout << (1 + (N - SUM)) << " " << (UM + (N - SUM)) << endl;
  return 0;
}
