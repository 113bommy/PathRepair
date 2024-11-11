#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
long long A;
int sz;
bool notPr[N];
vector<int> primes;
vector<long long> dvs[N];
map<pair<long long, int>, int> f;
bool isPrime(long long x) {
  if (x < 2) return 0;
  if (x == 2) return 1;
  for (int i = 0; i < primes.size() && 1ll * primes[i] * primes[i] <= x; i++)
    if (x % primes[i] == 0) return 1;
  return 0;
}
int dp(long long x, int cur) {
  if (f.count(pair<long long, int>(x, cur)))
    return f[pair<long long, int>(x, cur)];
  int res = 0;
  if (cur == sz) {
    if (x == 1)
      return 1;
    else if (x > N && isPrime(x - 1))
      return 1;
    else
      return 0;
  }
  res += dp(x, cur + 1);
  for (int i = 0; i < dvs[cur].size(); i++) {
    if (x % dvs[cur][i] == 0) res += dp(x / dvs[cur][i], cur + 1);
  }
  return f[pair<long long, int>(x, cur)] = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> A;
  notPr[0] = notPr[1] = 1;
  for (int i = 2; i < N; i++)
    if (!notPr[i]) {
      primes.push_back(i);
      for (int j = i + i; j < N; j += i) notPr[j] = 1;
    }
  for (int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    long long tmp = 1;
    bool ok = 0;
    while (tmp <= A) {
      tmp *= p;
      if (A % (tmp + 1) == 0) {
        if (!ok) ok = 1, ++sz;
        dvs[sz - 1].push_back(tmp + 1);
      }
    }
  }
  cout << dp(A, 0) << endl;
}
