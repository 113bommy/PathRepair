#include <bits/stdc++.h>
using namespace std;
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename T>
void read_integer(T &r) {
  bool sign = 0;
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c == '-') {
      sign = 1;
      break;
    }
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') break;
    r = r * 10 + (c - '0');
  }
  if (sign) r = -r;
}
long long binpowmod(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long c = binpowmod(a, b >> 1, mod);
  return (((c * c) % mod) * (b & 1 ? a : 1)) % mod;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long c = binpow(a, b >> 1);
  return c * c * (b & 1 ? a : 1);
}
inline int getbit(int x, int b) { return (x >> b) & 1; }
inline int setbit(int x, int b) { return x | (1 << b); }
inline void _setbit(int &x, int b) { x = setbit(x, b); }
inline long long setbit(long long x, int b) { return x | (1ll << b); }
inline void _setbit(long long &x, int b) { x = setbit(x, b); }
inline int unsetbit(int x, int b) { return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b) { x = unsetbit(x, b); }
inline int countbit(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline long long countbit(long long x) {
  return countbit(int(x & INT_MAX)) + countbit(int(x >> 32) & INT_MAX);
}
inline void printbit(int x, int len) {
  for (int i = len - 1; i >= 0; i--) printf("%d", getbit(x, i));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
template <typename A, typename B>
ostream &operator<<(ostream &stream, const pair<A, B> &p) {
  stream << "{" << p.first << "," << p.second << "}";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const vector<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A, typename B>
ostream &operator<<(ostream &stream, const map<A, B> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const set<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const stack<A> &v) {
  stack<A> st = v;
  stream << "[";
  while (!st.empty()) {
    stream << st.top() << " ";
    st.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const priority_queue<A> &v) {
  priority_queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.top() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const queue<A> &v) {
  queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const deque<A> &v) {
  deque<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop_front();
  }
  stream << "]";
  return stream;
}
void run();
int main() {
  srand(time(NULL));
  run();
  return 0;
}
const int mod = 1e9 + 7;
const int N = 100005;
bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
struct Fraction {
  long long a, b;
  Fraction(long long _a, long long _b) : a(_a), b(_b) {}
  Fraction operator+(const Fraction &other) const {
    long long g = b / gcd(b, other.b) * other.b;
    long long x = a * (g / b) + other.a * (g / other.b);
    long long q = gcd(x, g);
    x /= q;
    g /= q;
    return Fraction(x, g);
  }
  Fraction operator-(const Fraction &other) const {
    long long g = b / gcd(b, other.b) * other.b;
    long long x = a * (g / b) - other.a * (g / other.b);
    long long q = gcd(x, g);
    x /= q;
    g /= q;
    return Fraction(x, g);
  }
};
void run() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int m = n;
    while (!isPrime(m + 1)) --m;
    int nxt_prime = n + 1;
    while (!isPrime(nxt_prime)) ++nxt_prime;
    Fraction res = Fraction(1, 2) - Fraction(1, m + 1) +
                   Fraction(n - m, 1ll * (m + 1) * nxt_prime);
    0 ? (cout << "1"
              << " = " << (1) << ","
              << "m + 1"
              << " = " << (m + 1) << ","
              << "n - m"
              << " = " << (n - m) << ","
              << "nxt_prime"
              << " = " << (nxt_prime) << "\n")
      : cout;
    printf(0 ? "%lld" : "%I64d", res.a);
    putchar('/');
    printf(0 ? "%lld" : "%I64d", res.b);
    putchar('\n');
  }
}
