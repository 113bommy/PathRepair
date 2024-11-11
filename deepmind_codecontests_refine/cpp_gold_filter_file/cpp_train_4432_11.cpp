#include <bits/stdc++.h>
using namespace std;
double Fib(double x, double z);
string BinDec(unsigned long long x);
string StringInt(long long x);
unsigned long long StringInt(string x);
unsigned long long BinDec(string x);
unsigned long long POWMOD(unsigned long long x, unsigned long long y,
                          unsigned long long mod);
unsigned long long POWE(long long, long long);
struct trie {
  trie *child[2];
  int one, zero, is;
  trie() {
    memset(child, 0, sizeof(child));
    one = zero = is = 0;
  }
  void insert(char *str) {
    if (*str == 0)
      is = 1;
    else {
      int in = (*str) - '0';
      if (in == 0)
        zero++;
      else if (in == 1)
        one++;
      if (child[in] == 0) child[in] = new trie();
      child[in]->insert(str + 1);
    }
  }
  void remove(char *str) {
    if (*str == 0)
      is = 0;
    else {
      int in = *str - '0';
      if (in == 0) zero--;
      if (in == 1) one--;
      if (child[in] == 0) child[in] = new trie();
      child[in]->remove(str + 1);
    }
  }
  void get(char *str, long long &a, long long b) {
    if (*str == 0)
      ;
    else {
      int in = *str - '0';
      if (in == 0 && one >= 1) {
        a += b;
        child[1]->get(str + 1, a, b / 2);
      } else if (in == 1 && zero >= 1) {
        a += b;
        child[0]->get(str + 1, a, b / 2);
      } else
        child[in]->get(str + 1, a, b / 2);
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x, y, c, z;
  char a;
  cin >> x >> a;
  long long b = x / 4;
  if (x % 2 == 0) b++;
  b++;
  if (x % 4 == 0) b -= 2;
  b += (x / 4);
  y = ((b - 1) * 6);
  c = (x - 1) / 4;
  if (a == 'f') z = 1;
  if (a == 'e') z = 2;
  if (a == 'd') z = 3;
  if (a == 'a') z = 4;
  if (a == 'b') z = 5;
  if (a == 'c') z = 6;
  if (x % 2 == 0)
    cout << (c * 4) + y + 1 + z;
  else
    cout << (c * 4) + y + z;
  return 0;
}
double Fib(double x, double z) {
  int i = 0;
  double f = x, r = x, t;
  for (i = 2; i < z; i++) {
    t = f;
    f += r;
    r = t;
  }
  return f;
}
string BinDec(unsigned long long x) {
  string z;
  while (1) {
    z += ((x % 3) + '0');
    x /= 3;
    if (x == 0) break;
  }
  while (1) {
    if (z.size() == 30) break;
    z += '0';
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long BinDec(string x) {
  long long i;
  unsigned long long z = 1, a = 0;
  for (i = x.size() - 1; i >= 0; i--) {
    if (x[i] == '1') a += z;
    if (x[i] == '2') a += (2 * z);
    z *= 3;
  }
  return a;
}
unsigned long long StringInt(string x) {
  unsigned long long z = 0, i;
  for (i = 0; i < x.size(); i++) {
    z *= 10;
    z += (x[i] - '0');
  }
  return z;
}
string StringInt(long long x) {
  string z;
  while (x != 0) {
    z += (x % 10 + '0');
    x /= 10;
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long POWMOD(unsigned long long base, unsigned long long exp,
                          unsigned long long mod) {
  unsigned long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    res %= mod;
    exp /= 2;
    base = (base * base);
    base %= mod;
  }
  return res % mod;
}
unsigned long long POWE(long long base, long long exp) {
  unsigned long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    exp /= 2;
    base = (base * base);
  }
  return res;
}
