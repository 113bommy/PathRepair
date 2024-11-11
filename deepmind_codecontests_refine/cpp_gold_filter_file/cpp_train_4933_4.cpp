#include <bits/stdc++.h>
using namespace std;
long long int prime[1000000] = {0}, ans = 0;
long long int pwe(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int res = pwe(a, b / 2);
  res *= res;
  res %= 1000000007;
  if (b % 2)
    return (res * a) % 1000000007;
  else
    return (res);
}
void file() {}
long long int sumofdigits(long long int n) {
  long long int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
void sieve() {
  prime[0] = 0;
  prime[1] = 0;
  prime[2] = 1;
  long long int i, j, k;
  for (i = 3; i <= 1000000; i += 2) {
    prime[i] = 1;
  }
  for (i = 3; i <= 1000000; i++) {
    if (prime[i]) {
      for (j = i * i; j <= 1000000; j += 2 * i) prime[j] = 0;
    }
  }
}
bool cmp(pair<long long int, long long int> &a,
         pair<long long int, long long int> &b) {
  if (a.first != b.first) {
    return b.first > a.first;
  } else {
    return b.second > a.second;
  }
}
void solve() {
  long long int n, p, j;
  cin >> n >> p >> j;
  p--;
  j--;
  set<long long int> s;
  if (p == j) {
    cout << "0" << endl;
    return;
  }
  std::vector<long long int> v(n);
  for (long long int i = 0; i < n; ++i) cin >> v[i], v[i]--;
  long long int i = p, c = 0;
  while (1) {
    if (s.count(i)) {
      cout << "-1" << endl;
      return;
    }
    s.insert(i);
    i = v[i];
    c++;
    if (i == j) {
      cout << c << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
