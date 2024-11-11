#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long comb(long long a, long long b) {
  long long x = max(a - b, b), ans = 1;
  for (long long K = a, L = 1; K >= x + 1; K--, L++) {
    ans *= K;
    ans /= L;
  }
  return ans;
}
vector<int> primes;
vector<bool> mark(1002);
void sieve(int n) {
  int i, j, limit = sqrt(n * 1.) + 2;
  mark[1] = 1;
  for (i = 4; i <= n; i += 2) mark[i] = 1;
  primes.push_back(2);
  for (i = 3; i <= n; i += 2) {
    if (!mark[i]) {
      primes.push_back(i);
      if (i <= limit) {
        for (j = i * i; j <= n; j += i * 2) {
          mark[j] = 1;
        }
      }
    }
  }
}
void task() {
  int n;
  cin >> n;
  sieve(n);
  vector<int> ara;
  for (int K = 2; K <= n; K++) {
    if (mark[K]) continue;
    int i = K;
    while (i <= n) {
      ara.push_back(K);
      i *= K;
    }
  }
  cout << (int)ara.size() << "\n";
  for (int K = 0; K < (int)ara.size(); K++) cout << ara[K] << ' ';
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  task();
  return 0;
}
