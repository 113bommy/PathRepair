#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(std::pair<T1, T2> const &pair) const {
    std::size_t h1 = std::hash<T1>()(pair.first);
    std::size_t h2 = std::hash<T2>()(pair.second);
    return h1 ^ h2;
  }
};
unsigned long long max(unsigned long long a[], unsigned long long b[]) {
  unsigned long long r(*a);
  unsigned long long *k = a;
  while (k != b) {
    r = (r > (*k)) ? r : (*k);
    k++;
  }
  return r;
}
unsigned long long min(unsigned long long a[], unsigned long long b[]) {
  unsigned long long r(*a);
  unsigned long long *k = a;
  while (k != b) {
    r = (r < (*k)) ? r : (*k);
    k++;
  }
  return r;
}
void sieve(bool prime[], int n) {
  memset(prime, true, sizeof(bool) * n);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
template <typename T>
bool compair(pair<T, T> a, pair<T, T> b) {
  return a.second < b.second;
}
void solve() {
  long long n;
  cin >> n;
  cin.ignore();
  string s;
  cin >> s;
  long long res(0);
  for (size_t i(0); i < n; i++) {
    if (s[i] == '>') {
      break;
    } else
      res++;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '<')
      break;
    else
      res++;
  }
  cout << res;
}
int main() {
  { solve(); }
  return 0;
}
