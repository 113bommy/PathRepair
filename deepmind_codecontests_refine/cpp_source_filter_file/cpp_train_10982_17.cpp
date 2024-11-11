#include <bits/stdc++.h>
using namespace std;
long long MAX = 1000000007;
vector<long long> prime(1001);
vector<long long> getprm;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  auto q = power(a, b / 2);
  q = (q * q) % MAX;
  if (b % 2 == 0)
    return q % MAX;
  else
    return (q * a) % MAX;
}
long long modinv(long long val) { return power(val, MAX - 2); }
void primecalc() {
  fill(prime.begin(), prime.end(), 1);
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i < 1001; i++) {
    if (prime[i]) {
      getprm.push_back(i);
      for (int j = i + i; j < 1001; j += i) prime[j] = 0;
    }
  }
}
int main() {
  long long n;
  cin >> n;
  set<long long> ans;
  primecalc();
  for (int i = 1; i < n; i++) {
    if (prime[i]) {
      int j = 1;
      long long val = power(i, j);
      while (val <= n) {
        ans.insert(val);
        j++;
        val = power(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << " ";
  return 0;
}
