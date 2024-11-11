#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const long long mod = 1000000007;
long long p, k;
bool v[maxn];
int main() {
  cin >> p >> k;
  long long R = 1;
  for (int i = 1; i < p; i++)
    if (!v[i]) {
      long long t = i;
      while (!v[t]) {
        v[t] = 1;
        t = (t * k) % p;
      }
      R = (R * p) % mod;
    }
  if (k == 1) R = (R * p) % mod;
  cout << R << endl;
  return 0;
}
