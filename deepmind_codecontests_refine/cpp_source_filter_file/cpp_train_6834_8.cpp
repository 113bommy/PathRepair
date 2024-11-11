#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long p = power(a, b / 2);
  if (b & 1)
    return a * p * p;
  else
    return p * p;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long fact(long long n) {
  if (n == 0) return 1;
  if (n > 0) return n * fact(n - 1);
  return 1;
};
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int dfs(unordered_map<int, list<int> > &ma, vector<bool> &visited, int i) {
  visited[i] = 1;
  int cnt = 1;
  for (int j : ma[i]) {
    if (!visited[j]) {
      cnt += dfs(ma, visited, j);
    }
  }
  return cnt;
}
int main() {
  int k;
  cin >> k;
  if (k > 36)
    cout << -1;
  else {
    for (int i = 0; i < k / 2; i++) cout << 8;
    k -= (k / 2) * 2;
    while (k--) cout << 0;
  }
  return 0;
}
