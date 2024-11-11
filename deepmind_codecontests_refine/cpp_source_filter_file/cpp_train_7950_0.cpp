#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int n_ = 1e5 + 1000;
const long double PI = acos(-1.0);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
bool vowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  else
    return false;
}
class UnionFind {
 private:
  vector<int> p, rank, setSize;
  int numSets;

 public:
  UnionFind(int N) {
    setSize.assign(N, 1);
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        setSize[x] += setSize[y];
      } else {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y, n;
  cin >> x >> y >> n;
  long double a = x, b = y, frac, mn = MOD;
  long long mnn = -1, mnd = -1;
  frac = a / b;
  for (long long i = 1; i <= n; i++) {
    long double c = i;
    long long d, e;
    e = floor(frac * c);
    d = ceil(frac * c);
    if ((mn - abs(e / c - frac)) > 1e-6) {
      mn = abs(e / c - frac);
      mnn = e;
      mnd = c;
    }
    if ((mn - abs(d / c - frac)) > 1e-6) {
      mn = abs(d / c - frac);
      mnn = d;
      mnd = c;
    }
  }
  cout << mnn << "/" << mnd;
  return 0;
}
