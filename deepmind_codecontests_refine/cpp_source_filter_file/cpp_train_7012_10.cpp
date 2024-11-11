#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, m;
  cin >> n >> m;
  long long int pot2 = 1;
  for (int i = 1; i <= m; i++) {
    pot2 *= 2;
    pot2 %= 1000000007;
  }
  long long int wyn = 1;
  for (int i = 1; i <= n; i++) {
    wyn *= (pot2 - i);
    wyn %= 1000000007;
  }
  cout << wyn << endl;
  return 0;
}
