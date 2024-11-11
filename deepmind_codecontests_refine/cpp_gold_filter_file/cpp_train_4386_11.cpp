#include <bits/stdc++.h>
using namespace std;
long long INFF = 1000000000000000005LL;
template <typename T>
void scan(T &x) {
  x = 0;
  bool neg = 0;
  register T c = getchar();
  if (c == '-') neg = 1, c = getchar();
  while ((c < 48) || (c > 57)) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x *= -1;
}
template <typename T>
void print(T n) {
  bool neg = 0;
  if (n < 0) n *= -1, neg = 1;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  --i;
  if (neg) putchar('-');
  while (i >= 0) putchar(snum[i--]);
  putchar('\n');
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int getSum(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long int factorial(long long int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}
int countDigit(long long n) {
  int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}
const int NN = 1e9 + 7;
unsigned long long pow1(long long int base, long long int powerRaised) {
  if (powerRaised != 0)
    return ((base)*pow1(base, powerRaised - 1)) % NN;
  else
    return 1;
}
bool prime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int getC(map<string, int> z, string a, string b) {
  if (z.count(a) && z.count(b)) {
    return z[a] + z[b];
  }
  return INT_MAX;
}
typedef struct array_single_int {
  int *data;
  int size;
} array_single_int;
int noOfProducts(array_single_int order, int disAmount) {
  int answer = 0;
  int n = order.size;
  int *a = order.data;
  for (int i = 0; i < n; i++) {
    if ((disAmount % abs(a[i])) == 0) {
      answer++;
    }
  }
  return answer;
}
void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int cnt = 0;
  int index = n - 1;
  for (int i = 0; i < n - 1; i++) {
    int a1 = (int)a[i];
    int a2 = (int)a[i + 1];
    if (a1 - a2 > 0) {
      index = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == index) continue;
    cout << a[i];
  }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n = 1, a = 0;
  for (a = 0; a < n; ++a) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
