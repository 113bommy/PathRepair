#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int mod = 1000000009;
int main() {
  int n;
  cin >> n;
  long long res = 2;
  long long curr = 1;
  long long sum = 1;
  long long prev = 1;
  for (int i = 4; i <= n; i += 2) {
    res += (sum * 4);
    res %= mod;
    prev += (curr * 4);
    prev %= mod;
    curr = (curr * 2);
    curr %= mod;
    sum *= prev;
    sum %= mod;
  }
  cout << (2 * res * res + 2) % mod << endl;
  return 0;
}
