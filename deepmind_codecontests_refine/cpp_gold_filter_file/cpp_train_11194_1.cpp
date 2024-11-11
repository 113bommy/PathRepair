#include <bits/stdc++.h>
using namespace std;
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
  int n, p, q, k(1);
  cin >> n >> p >> q;
  int oc = (n + 1) / 2;
  int ec = n / 2;
  int odd(1), eve(2);
  if (p * q < n) {
    cout << -1;
    return;
  }
  for (size_t i(0); i < p; i++) {
    for (size_t j(0); j < q; j++) {
      if (k) {
        if (oc) {
          cout << odd << ' ';
          odd += 2;
          oc--;
        } else
          cout << 0 << ' ';
      } else {
        if (ec) {
          cout << eve << ' ';
          eve += 2;
          ec--;
        } else
          cout << 0 << ' ';
      }
      k = (k == 1) ? 0 : 1;
    }
    if (q % 2 == 0) {
      k = (k == 1) ? 0 : 1;
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  { solve(); }
  return 0;
}
