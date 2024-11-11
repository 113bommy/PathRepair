#include <bits/stdc++.h>
using namespace std;
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
  long long int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  --i;
  if (neg) putchar('-');
  while (i >= 0) putchar(snum[i--]);
  printf(" ");
}
long long int readll() {
  bool minus = false;
  long long int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
long long int readint() {
  char r;
  bool start = false, neg = false;
  long long int ret = 0;
  while (true) {
    r = getchar();
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
      continue;
    }
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
      break;
    }
    if (start) ret *= 10;
    start = true;
    if (r == '-')
      neg = true;
    else
      ret += r - '0';
  }
  if (!neg)
    return ret;
  else
    return -ret;
}
bool subsetSums(long long int arr[], long long int n, long long int k) {
  long long total = 1 << n;
  for (long long i = 0; i < total; i++) {
    long long sum = 0;
    for (long long int j = 0; j < n; j++)
      if (i & (1 << j)) sum += arr[j];
    if (sum == k) return true;
  }
  return false;
}
void solve() {
  long long int k;
  scan(k);
  long long int n = k % 25;
  long long int t = k / 25;
  string str = "abcdefghijklmnopqrstuvwxyz";
  if (n > 0) {
    string b = str.substr(0, n + 1);
    reverse(b.begin(), b.end());
    cout << b;
  }
  reverse(str.begin(), str.end());
  while (t--) {
    cout << str;
  }
  cout << endl;
}
long long int phi(long long int n) {
  if (n == 1) return 2;
  long long int i;
  long long int result = n;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
bool checkprime(long long int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  long long int i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) break;
  }
  if (i * i > n)
    return true;
  else
    return false;
}
bool lexicographical_compare(string s1, string s2) {
  for (long long int i = 0; i < min(s1.length(), s2.length()); i++) {
    if (s1[i] < s2[i]) return true;
    if (s1[i] > s2[i]) return false;
  }
  if (s1.length() <= s2.length()) return true;
}
long long int reverse(long long int n) {
  long long int sum = 0;
  long long int i = 0;
  long long int temp = n;
  long long int len = 0;
  while (temp > 0) {
    len++;
    temp /= 10;
  }
  while (n > 0) {
    sum += (n % 10) * pow(10, len - i - 1);
    i++;
    n /= 10;
  }
  return sum;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modularinverse(long long int a, long long int p) {
  return power(a, p - 2, p);
}
bool prime[10000000];
void sieve() {
  prime[1] = false;
  int i, j;
  for (i = 2; i < 10000000; ++i) {
    prime[i] = true;
  }
  for (i = 2; i * i < 10000000; ++i) {
    if (prime[i]) {
      for (j = 2; j * i < 10000000; ++j) prime[i * j] = false;
    }
  }
}
int digits(int n) {
  int count = 0;
  while (n > 0) {
    count++;
    n /= 10;
  }
  return count;
}
bool check(int n) {
  int count = 0;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0 && checkprime(i)) {
      ++count;
    } else if (n % i == 0) {
      if (checkprime(n / i)) ++count;
    }
  }
  if (count >= 3)
    return true;
  else
    return false;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (n == 2) {
    cout << 2;
    return 0;
  }
  if (n == 3) {
    cout << 6;
    return 0;
  }
  if (n % 2) {
    cout << n * (n - 1) * (n - 2);
    return 0;
  }
  if (n % 3 == 0)
    cout << (n - 1) * (n - 2) * (n - 3);
  else
    cout << n * (n - 1) * (n - 3);
}
