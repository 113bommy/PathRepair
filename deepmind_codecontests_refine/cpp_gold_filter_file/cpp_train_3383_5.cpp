#include <bits/stdc++.h>
using namespace std;
bool notprimes[1200008];
int rob[1200008];
int amPr[1200008];
void getpr(int n) {
  notprimes[0] = notprimes[1] = true;
  for (int i = 2; i <= n; ++i)
    if (!notprimes[i])
      if (i * 1ll * i <= n)
        for (int j = i * i; j <= n; j += i) notprimes[j] = true;
}
bool isprime(int x) {
  if (x == 2) return true;
  for (int i = 2; i <= sqrt(x) + 1; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool rub(int x) {
  stringstream ss;
  ss << x;
  string g = ss.str();
  for (int i = 0; i < (g.size() + 1) / 2; i++) {
    if (g[i] != g[g.size() - i - 1]) return false;
  }
  return true;
}
void rubbing(int n) {
  int r = 0;
  for (int i = 1; i <= n; i++) {
    if (rub(i)) r++;
    rob[i] = r;
  }
  int primes = 0;
  for (int i = 2; i <= n; i++) {
    if (!notprimes[i]) primes++;
    amPr[i] = primes;
  }
}
int main() {
  ios::sync_with_stdio(0);
  ;
  long long p, q;
  getpr(1200008 - 10);
  rubbing(1200008 - 10);
  cin >> p >> q;
  int l = 1, r = 1200008 - 10, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (q * amPr[mid] <= p * rob[mid]) {
      l = mid;
    } else {
      r = mid;
    }
    if (l + 50 <= r) {
      for (int i = r; i >= l; i--) {
        if (q * amPr[i] <= p * rob[i]) {
          cout << i << "\n";
          return 0;
        }
      }
      break;
    }
  }
  cout << "Palindromic tree is better than splay tree\n";
  return 0;
};
