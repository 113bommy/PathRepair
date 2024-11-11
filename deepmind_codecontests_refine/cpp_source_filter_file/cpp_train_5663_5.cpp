#include <bits/stdc++.h>
using namespace std;
long long ABS(long long a) {
  if (a >= 0) return a;
  return -a;
}
struct num {
  long long a;
  long long mod;
  num(long long a) { this->a = a; }
  num() {}
  num(long long a, long long mod) {
    this->a = a;
    this->mod = mod;
  }
  num operator+(const num &o) const { return num((o.a + a) % mod, mod); }
  num operator-(const num &o) const { return num((mod - o.a + a) % mod, mod); }
  bool operator==(const num &o) const { return a == o.a; }
  num operator*(const num &o) const { return num((a * o.a) % mod, mod); }
  num operator/(const num &o) const {
    num buffer = *this;
    return buffer * pow(o, mod - 2);
  }
  num pow(const num &o, long long n) const {
    num ans = num(1, mod);
    num buffer = o;
    while (n) {
      if (!(n & 1)) {
        buffer = buffer * buffer;
        n >>= 1;
      } else {
        ans = ans * buffer;
        n--;
      }
    }
    return ans;
  }
};
bool check(long long p) {
  long long edge = pow(p, .5);
  for (long long i = 2; i <= edge; i++)
    if (!(p % i)) return false;
  return true;
}
long long generate(long long range) {
  while (true) {
    if (check(range)) return range;
    range++;
  }
}
int main() {
  long long p, q, n;
  vector<long long> mas;
  cin >> p >> q >> n;
  mas.resize(n);
  for (int i = 0; i < n; i++) cin >> mas[i];
  reverse(mas.begin(), mas.end());
  long long range = 1e+7;
  for (int j = 0; j < 20; j++) {
    long long mod = generate(range);
    range = mod + 1;
    if (q % mod == 0) continue;
    num left = num(p, mod) / num(q, mod);
    num right = num(0, mod);
    bool ok = true;
    for (int i = 0; i < mas.size(); i++) {
      right = right + num(mas[i], mod);
      if (i != mas.size() - 1) {
        if (right.a == 0) {
          ok = false;
          break;
        }
        right = num(1, mod) / right;
      }
    }
    if (ok)
      if (!(left == right)) {
        cout << "NO";
        return 0;
      }
  }
  cout << "YES";
  return 0;
}
