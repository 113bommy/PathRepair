#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
unsigned long long int bigMod(unsigned long long int b,
                              unsigned long long int p,
                              unsigned long long int m) {
  b = b % m;
  if (p == 0)
    return 1;
  else if (p % 2 == 0)
    return ((unsigned long long int)pow(bigMod(b, p / 2, m), 2)) % m;
  else
    return ((unsigned long long int)pow(bigMod(b, (p - 1) / 2, m), 2) * b) % m;
}
unsigned long long int nCr(unsigned long long int n, unsigned long long int r) {
  unsigned long long int ans = 1;
  if (r >= n - r) {
    for (unsigned long long int i = r + 1; i <= n; i++) {
      ans = ans * i;
    }
    for (unsigned long long int i = 1; i <= n - r; i++) {
      ans = ans / i;
    }
  } else {
    for (unsigned long long int i = n - r + 1; i <= n; i++) {
      ans = ans * i;
    }
    for (unsigned long long int i = 1; i <= r; i++) {
      ans = ans / i;
    }
  }
  return ans;
}
unsigned long long int fib(unsigned long long int a) {
  const long double root5 = sqrt(5);
  const long double root5plus1div2 = (root5 + 1) / 2;
  return round(pow(root5plus1div2, a) / root5);
}
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
unsigned long long int lcm(unsigned long long int a, unsigned long long int b) {
  return ((a * b) / gcd(a, b));
}
bool isPrime(unsigned long long int a) {
  if (a == 1)
    return false;
  else if (a == 2)
    return true;
  if (a % 2 == 0) return false;
  for (int i = 3; i <= sqrt(a); i += 2) {
    if (a % i == 0) return false;
  }
  return true;
}
bool isComposite(unsigned long long int a) {
  if (isPrime(a))
    return false;
  else
    return true;
}
bool coPrime(unsigned long long int a, unsigned long long int b) {
  if (gcd(a, b) == 1)
    return true;
  else
    return false;
}
long double toRadian(long double deg) { return (deg * acos(-1) / 180); }
unsigned long long int strToInt(string a) {
  int len = a.length();
  int power = 0;
  unsigned long long int tot = 0;
  for (int i = len - 1; i >= 0; i--) {
    tot = tot + pow(10, power) * (a[i] - '0');
    power++;
  }
  return tot;
}
bool desc(int a, int b) { return a > b; }
unsigned long long int mex(int* arr, int n) {
  sort(arr, arr + n);
  int now = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == now + 1) {
      now++;
    } else if (arr[i] == now) {
    } else {
      return now + 1;
    }
  }
  return now + 1;
}
unsigned long long int modInv(unsigned long long int n,
                              unsigned long long int p) {
  return bigMod(n, p - 2, p);
}
long double slope(long double xdiff, long double ydiff) {
  return (ydiff / xdiff);
}
bool binSearch(long long int* arr, long long int n, long long int target) {
  unsigned long long int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] >= target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (arr[l] == target) {
    return true;
  } else {
    return false;
  }
}
int ascii(char x) { return int(x); }
long double sine(long double x) { return sin(toRadian(x)); }
long double cosine(long double x) { return cos(toRadian(x)); }
long double tangent(long double x) { return tan(toRadian(x)); }
unsigned long long int hammDist(string a, string b,
                                unsigned long long int len) {
  unsigned long long int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] != b[i]) cnt++;
  }
  return cnt;
}
unsigned long long int binStrToInt(string a, unsigned long long int len) {
  unsigned long long int num = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (a[i] == '1') {
      num = num + pow((unsigned long long int)2, len - i - 1);
    }
  }
  return num;
}
bool side(char t) {
  if (t >= 'a') {
    return (t == 'a' || t == 'h');
  } else {
    return (t == '1' || t == '8');
  }
}
void solve() {
  string a;
  cin >> a;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '.') {
      if (a[i - 1] == '9') {
        cout << "GOTO Vasilla.\n";
        return;
      }
      if (a[i + 1] > '4') {
        a[i - 1]++;
      }
      break;
    }
  }
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '.') break;
    cout << a[i];
  }
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  solve();
}
