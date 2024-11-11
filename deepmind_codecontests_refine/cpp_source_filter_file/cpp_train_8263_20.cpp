#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
const double Pi = acos(-1.0);
using namespace std;
const long long MOD = 1000000007;
set<vector<long long> > used;
map<pair<vector<long long>, vector<long long> >, long long> usedd;
vector<long long> a;
long long n;
vector<long long> b;
const long long ans8[9] = {40320, 0, 40320, 0, 11760, 0, 3920, 0, 638};
const long long ans10[11] = {3628800, 0, 3628800, 0, 1512000, 0,
                             383040,  0, 66060,   0, 9268};
const long long ans9[10] = {362880, 0, 362880, 0, 151200, 0, 38304, 0, 6606, 0};
void solve(long long n, long long k) {
  if (usedd[make_pair(a, b)]) return;
  usedd[make_pair(a, b)] = 1;
  used.insert(a);
  used.insert(a);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (b[i] && b[j]) {
        b[i]--;
        b[j]--;
        swap(a[i], a[j]);
        solve(n, k - 1);
        swap(a[i], a[j]);
        b[i]++;
        b[j]++;
      }
    }
  }
}
bool useddd[2000000];
long long masss[2000000];
long long fact(long long x) {
  if (x == 0) return 1;
  return x * fact(x - 1);
}
long long f(long long n, long long x) {
  if (n >= 5 && (x <= 2)) {
    return fact(n);
  }
  if (n > x) return ((n)*f(n - 1, x)) % MOD;
  if (n == x && n > 4) {
    masss[1] = 1;
    masss[2] = 2;
    for (int i = 3; i <= n; i++) {
      masss[i] = (masss[i - 1] + (i - 1) * masss[i - 2]) % MOD;
    }
    return masss[n];
  }
  used.clear();
  a.resize(n);
  b.resize(n);
  for (long long i = 0; i < n; i++) {
    a[i] = i;
  }
  long long sum = 0;
  for (long long i = 0; i < x; i++) {
    b[i] = 1;
    sum++;
  }
  for (long long i = x; i < n; i++) {
    b[i] = 2;
    sum += 2;
  }
  solve(n, sum / 2);
  long long ans = used.size();
  return ans;
}
int main() {
  cin >> n;
  long long num = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x == 1) num++;
  }
  cout << f(n, num) << endl;
  return 0;
}
