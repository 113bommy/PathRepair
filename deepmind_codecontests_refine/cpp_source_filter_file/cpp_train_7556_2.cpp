#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
  cin >> N;
  long long d = 1;
  while (d * 10 < N) d *= 10;
  cout << ((N + d) / d) * d - N << '\n';
  return 0;
}
