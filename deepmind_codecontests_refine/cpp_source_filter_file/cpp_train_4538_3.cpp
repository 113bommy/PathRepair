#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long MOD = inf + 7;
template <class T>
int getbit(T x, int pos) {
  return (x >> (pos - 1)) & 1;
}
template <class T>
void turn_on(T &x, int pos) {
  x = x | (1 << (pos - 1));
}
template <class T>
void turn_off(T &x, int pos) {
  x = x & ~(1 << (pos - 1));
}
vector<long long> p;
void phi(long long &n) {
  p.clear();
  long long tmp = n;
  for (long long i = 2; i * i <= tmp; ++i)
    if (tmp % i == 0) {
      int k = 1;
      while (tmp % i == 0) {
        tmp /= i;
        ++k;
      }
      p.push_back(i);
    }
  if (tmp != 1) p.push_back(tmp);
  for (int i = 0; i <= (int)p.size() - 1; ++i) n = n / p[i] * (p[i] - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= k; i += 2) {
    phi(n);
    if (n == 1) break;
  }
  cout << n;
}
