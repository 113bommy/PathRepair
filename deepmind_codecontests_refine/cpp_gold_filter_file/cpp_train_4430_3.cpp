#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long maxn = 105;
const long long inf = 1ll << 50;
long long prime[maxn];
vector<long long> primes;
vector<long long> squares;
void pre() {
  for (long long i = 2; i < maxn; i++) {
    if (prime[i]) continue;
    for (long long j = i * i; j < maxn; j += i) {
      prime[j] = 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  for (int i = 2; i <= 50; i++) {
    if (!prime[i]) {
      primes.push_back(i);
    }
  }
  for (auto it : primes) {
    if (it * it <= 100) {
      squares.push_back(it * it);
    } else {
      break;
    }
  }
  assert(primes.size() + squares.size() <= 20);
  long long cnt1 = 0, cnt2 = 0;
  string s;
  for (auto it : primes) {
    cout << it << endl;
    cin >> s;
    if (s == "yes") cnt1++;
  }
  for (auto it : squares) {
    cout << it << endl;
    cin >> s;
    if (s == "yes") cnt2++;
  }
  if (cnt1 > 1 || cnt2 > 0) {
    cout << "composite" << endl;
  } else {
    cout << "prime" << endl;
  }
  return 0;
}
