#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void findPrime(vector<long long> &c) {
  vector<bool> a(1e5 + 1);
  a[0] = true;
  a[1] = true;
  for (long long i = 2; i <= sqrt(1e5); i++) {
    if (!a[i]) {
      for (long long j = i * i; j <= 1e5; j = j + i) a[j] = true;
    }
  }
  for (long long i = 2; i <= 1e5; i++) {
    if (!a[i]) c.push_back(i);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> a;
  findPrime(a);
  vector<long long> b;
  for (long long i = 0; i < a.size() && k != 1 && a[i] <= n; i++) {
    while (n % a[i] == 0 && k != 1 && a[i] <= n) {
      n = n / a[i];
      b.push_back(a[i]);
      k--;
    }
  }
  if (k != 1 || n == 1)
    cout << -1 << endl;
  else {
    for (auto it = (b).begin(); it != (b).end(); it++) cout << *it << " ";
    cout << n << endl;
  }
  return 0;
}
