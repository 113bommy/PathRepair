#include <bits/stdc++.h>
using namespace std;
bitset<10000010> bs;
vector<int> primes;
void sieve(long long int upperbound) {
  long long int _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long int i = 2; i <= _sieve_size; i++)
    if (bs[i]) {
      for (long long int j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      primes.push_back((int)i);
    }
}
int main() {
  int n, x;
  int a[100005] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a[x] = i + 1;
  }
  int q;
  long int v = 0, p = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x;
    v += a[x];
    p += (n - a[x] + 1);
  }
  cout << v << " " << p;
}
