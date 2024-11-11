#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
const int n = 300000;
unsigned long long gcd(unsigned long long a, unsigned long long bs) {
  if (bs == 0) return a;
  a %= bs;
  return gcd(bs, a);
}
bool isPrime[1000001];
int main() {
  int n, k;
  cin >> n >> k;
  long long ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  long long val[n], want[n];
  for (int i = 0; i < n; i++) {
    long long a = 1, b = 1;
    for (int j = 2; j * j <= ar[i]; j++) {
      int amt = 0;
      while (ar[i] % j == 0) {
        ar[i] /= j;
        amt += 1;
      }
      a *= pow(j, amt % k);
      b *= pow(j, (k - (amt % k)) % k);
    }
    if (ar[i] > 1) {
      a *= ar[i];
      b *= pow(ar[i], k - 1);
    }
    val[i] = a;
    want[i] = b;
  }
  map<long long, int> wants;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (wants.find(val[i]) != wants.end()) {
      ans += wants[val[i]];
    }
    if (wants.find(want[i]) == wants.end())
      wants[want[i]] = 1;
    else
      wants[want[i]] += 1;
  }
  cout << ans << endl;
}
