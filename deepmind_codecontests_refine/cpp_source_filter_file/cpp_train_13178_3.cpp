#include <bits/stdc++.h>
using namespace std;
const unsigned long long m = 256;
const unsigned long long N = 5 * 1000000 + 2;
string s;
unsigned long long hash_l = 0, hash_r = 0, e = 1, i, deg[N], sum = 0;
int main() {
  memset(deg, 0, sizeof(deg));
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    hash_l = hash_l * m + s[i];
    hash_r = s[i] * e + hash_r;
    e *= m;
    sum += (hash_l == hash_r ? (deg[i + 1] = deg[(i + 1) / 2] + 1) : 0);
  }
  cout << sum;
}
