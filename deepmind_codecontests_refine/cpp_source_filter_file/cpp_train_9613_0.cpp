#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  vector<long long> pos(4, 1);
  if (x == 1) {
    cout << 0 << endl;
    return 0;
  }
  pos[3] = 0;
  long long MOD = 1e9 + 7;
  vector<long long> aux(4, 0);
  for (int i = 0; i < x - 2; i++) {
    aux[0] = (pos[1] + pos[2] + pos[3]) % MOD;
    aux[1] = (pos[0] + pos[2] + pos[3]) % MOD;
    aux[2] = (pos[0] + pos[1] + pos[3]) % MOD;
    aux[3] = (pos[0] + pos[1] + pos[2]) % MOD;
    pos = aux;
  }
  cout << pos[0] + pos[1] + pos[2] << endl;
  return 0;
}
