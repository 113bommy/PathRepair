#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-10);
bool comp(unsigned long long x, unsigned long long y) { return x > y; }
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};
bool isprime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
vector<int> getdividors(int n) {
  vector<int> dividors;
  int i;
  for (i = 1; i * i < n; i++) {
    if (n % i == 0) {
      dividors.push_back(i);
      dividors.push_back(n / i);
    }
  }
  if (i * i == n) dividors.push_back(i);
  return dividors;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long C(long long a, long long b) {
  if (b > a - b) return C(a, a - b);
  vector<long long> nom, den;
  for (long long i = a; i > a - b; i--) nom.push_back(i);
  for (long long i = 2; i <= b; i++) den.push_back(i);
  long long lenNom = nom.size();
  long long lenDen = den.size();
  for (int i = 0; i < lenNom; i++) {
    for (int j = 0; j < lenDen; j++) {
      long long g = gcd(nom[i], den[j]);
      if (g > 1) {
        nom[i] /= g;
        den[j] /= g;
      }
    }
  }
  long long top = 1;
  long long bot = 1;
  for (int i = 0; i < lenNom; i++) top *= nom[i];
  for (int i = 0; i < lenDen; i++) bot *= den[i];
  return top / bot;
}
void solveB() {
  double a, x, y;
  cin >> a >> x >> y;
  int res = -1;
  if (x > -a / 2 && x < a / 2 && y > 0 && y < a)
    res = 1;
  else {
    int _a = a;
    int _y = y - _a;
    int rem = _y % (2 * _a);
    _y /= 2 * _a;
    if (rem > 0 && rem < a) {
      if (x > -a / 2 && x < a / 2) res = _y * 3 + 2;
    } else if (rem > a && rem < 2 * a) {
      if (x > 0 && x < a) res = _y * 3 + 4;
      if (x < 0 && x > -a) res = _y * 3 + 3;
    }
    cout << res << endl;
  }
}
int main() {
  solveB();
  return 0;
}
