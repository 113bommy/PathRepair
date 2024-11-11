#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> even;
vector<long long> odd;
bool prime[2000050];
long long cnt, ans1, ans2, ele1, ele2, ele, f;
bool isprime(long long x) { return prime[x]; }
void sieve() {
  memset(prime, true, sizeof prime);
  prime[1] = prime[0] = false;
  for (long long i = 2; i <= 2000005; i++) {
    if (prime[i]) {
      for (long long j = 2 * i; j <= 2000005; j += i) {
        prime[j] = false;
      }
    }
  }
}
int main() {
  sieve();
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    f = x;
    if (x == 2) {
      ans2 = 1;
      ele1 = 2;
    }
    if (x == 1) {
      cnt++;
      continue;
    }
    if (x & 1)
      odd.push_back(x);
    else
      even.push_back(x);
  }
  if (cnt == n) {
    cout << cnt << endl;
    while (cnt--) cout << "1 ";
    cout << endl;
    return 0;
  }
  ans1 = cnt;
  if (cnt) {
    for (auto i : even) {
      if (isprime(i + 1)) {
        ans1 = 1 + cnt;
        ele = i;
        break;
      }
    }
  }
  for (auto i : odd) {
    if (isprime(i)) {
      ans2 = 1;
      ele1 = i;
    }
    for (auto j : even) {
      if (isprime(i + j)) {
        ele1 = i;
        ele2 = j;
        ans2 = 2;
        break;
      }
    }
  }
  if (ans1 == 0 && ans2 == 0) {
    cout << "1\n";
    cout << f << endl;
    return 0;
  }
  if (ans1 >= ans2) {
    cout << ans1 << endl;
    while (cnt--) {
      cout << "1 ";
    }
    if (ele != 0) {
      cout << ele << endl;
    }
    return 0;
  }
  {
    cout << ans2 << endl;
    if (ans2 == 1)
      cout << ele1 << endl;
    else
      cout << ele1 << " " << ele2 << endl;
  }
  return 0;
}
