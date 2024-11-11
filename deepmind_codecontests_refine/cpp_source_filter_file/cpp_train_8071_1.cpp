#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  map<char, int> M;
  for (int i = 0; i < 9; ++i) M[i + '0'] = i;
  for (int i = 'A', conta = 0; i <= 'Z'; ++i, conta++)
    M[conta + 'A'] = conta + 10;
  for (int i = 'A', conta = 0; i <= 'Z'; ++i, conta++)
    M[conta + 'a'] = conta + 36;
  M['-'] = 62;
  M['_'] = 63;
  string cad;
  cin >> cad;
  map<char, long long> same;
  for (int i = 0; i < 64; ++i)
    for (int j = 0; j < 64; ++j) same[i & j]++;
  long long ans = 1;
  for (int i = 0; i < cad.size(); ++i) ans = (ans * same[M[cad[i]]]) % MOD;
  cout << ans << '\n';
  return 0;
}
