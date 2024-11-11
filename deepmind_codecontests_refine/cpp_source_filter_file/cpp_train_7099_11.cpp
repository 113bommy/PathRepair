#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int modExp(long long int b, long long int e, long long int mod) {
  long long int res = 1;
  while (e > 0) {
    if (e & 1) res = res * b % mod;
    b = b * b % mod;
    e >>= 1;
  }
  return res % mod;
}
long long int factorial(long long int n) {
  long long int r = 1;
  for (long long int i = 1; i <= n; ++i) {
    r *= i;
  }
  return r;
}
int q, n, nkid;
int parent[205] = {0};
int size[205] = {0};
void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
}
int find_set(int v) {
  return parent[v] = parent[v] == v ? v : find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b) return;
  if (size[a] < size[b]) swap(a, b);
  parent[b] = a;
  size[a] += size[b];
}
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) make_set(i);
    for (int i = 1; i <= n; ++i) {
      cin >> nkid;
      union_sets(i, nkid);
    }
    for (int i = 1; i <= n; ++i) cout << size[parent[i]] << " ";
    cout << endl;
  }
  return 0;
}
