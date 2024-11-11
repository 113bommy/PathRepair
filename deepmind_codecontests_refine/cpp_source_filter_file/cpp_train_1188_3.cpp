#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<pair<int, int> > pride;
int n;
vector<long long> factmem(100047, -1);
long long power(long long base, long long exp) {
  long long res = 1, pom = base;
  while (exp > 0) {
    if (exp % 2 == 1) res *= pom;
    res %= mod;
    exp /= 2;
    pom *= pom;
    pom %= mod;
  }
  return res;
}
long long factorial(long long a) {
  if (factmem[a] == -1) {
    factmem[a] = ((long long)(a)*factorial(a - 1)) % mod;
  }
  return factmem[a];
}
long long divide(long long b, long long a) {
  long long inv = power(a, mod - 2);
  return (b * inv) % mod;
}
long long choose(long long a, long long b) {
  return divide(factorial(a), (factorial(a - b) * factorial(b)) % mod);
}
bool contains(pair<int, int> a, pair<int, int> b) {
  return a.first <= b.first && b.second <= a.second;
}
long long solve(int from, int to, int prislo) {
  if (prislo >= pride.size()) {
    return choose(n - (to - from), from);
  }
  int ind = pride[prislo].second;
  int t = pride[prislo].first;
  pair<int, int> tot(0, n);
  pair<int, int> left(ind - t, ind + 1), right(ind, ind + t + 1);
  pair<int, int> on(from, to), ja(ind, ind + 1);
  if (contains(on, ja)) return 0;
  if (contains(tot, right) && contains(right, on)) {
    return (choose(t - (to - from), from - ind - 1) *
            solve(ind, ind + t + 1, prislo + 1)) %
           mod;
  }
  if (contains(tot, left) && contains(left, on)) {
    return (choose(t - (to - from), ind - to) *
            solve(ind - t, ind + 1, prislo + 1)) %
           mod;
  }
  return 0;
}
int main() {
  factmem[0] = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t > 0) {
      pride.push_back(pair<int, int>(t - 1, i));
    }
  }
  sort(pride.begin(), pride.end());
  if (pride.size() == 0) {
    long long res = power(2, n - 1);
    cout << res << endl;
    return 0;
  }
  int t = pride[0].first, ind = pride[0].second;
  long long res = 0;
  if (t == 0) {
    res = solve(ind, ind + 1, 1);
  } else {
    if (t + ind < n) res += solve(ind, ind + t + 1, 1) * pow(2, t - 1);
    res %= mod;
    if (ind - t >= 0) res += solve(ind - t, ind + 1, 1) * pow(2, t - 1);
    res %= mod;
  }
  cout << res << endl;
  return 0;
}
