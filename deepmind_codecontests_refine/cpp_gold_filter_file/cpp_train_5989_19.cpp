#include <bits/stdc++.h>
using namespace std;
long long revNumber(long long n) {
  long long b = 0;
  while (n != 0) {
    b = b * 10 + n % 10;
    n /= 10;
  }
  return b;
}
long long leapYearCheck(long long year) {
  if (year % 4 != 0)
    return 0;
  else if (year % 100 != 0)
    return 1;
  else if (year % 400 != 0)
    return 0;
  else
    return 1;
}
long long countDivisor(long long n) {
  long long ck = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ck++;
      if (i != n / i) ck++;
    }
  }
  return ck;
}
long long primeFactorsCount(long long n) {
  long long gf = 0;
  while (n % 2 == 0) {
    gf++;
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      gf++;
      n = n / i;
    }
  }
  if (n > 2) {
    gf++;
  }
  return gf;
}
long long factorial(long long n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}
long long binarySearch(long long high, long long sV, long long arr[]) {
  long long low = 0;
  while (low <= high) {
    long long mid = (high + low) / 2;
    if (sV == arr[mid])
      return mid + 1;
    else if (sV > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
bool checkPrime(int n) {
  int i;
  if (n <= 1) return false;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void simpleSieve(int limit) {
  bool mark[limit];
  memset(mark, true, sizeof(mark));
  for (int p = 2; p * p < limit; ++p) {
    if (mark[p] == true) {
      for (int i = p * 2; i < limit; i += p) mark[i] = false;
    }
  }
  for (int p = 2; p < limit; ++p) {
    if (mark[p] == true) cout << p << " ";
  }
}
int divSum(int n) {
  int result = 0;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (i == (n / i))
        result += i;
      else
        result += (i + n / i);
    }
  }
  return (result + 1);
}
bool isPerfectSquare(int n) {
  for (int sum = 0, i = 1; sum < n; i += 2) {
    sum += i;
    if (sum == n) return true;
  }
  return false;
}
bool isPowerOfTwo(long long x) { return (x && !(x & (x - 1))); }
bool checksqrt(double f) { return (sqrt(f) * sqrt(f) == f); }
int Combination(int n, int r) {
  if (n == r) return 1;
  if (r == 1) return n;
  return Combination(n - 1, r) + Combination(n - 1, r - 1);
}
int Permutation(int n, int r) { return factorial(n) / factorial(n - r); }
int middle(int a, int b, int c) {
  if ((a <= b && b <= c) || (c <= b && b <= a))
    return b;
  else if ((b <= a && a <= c) || (c <= a && a <= b))
    return a;
  else
    return c;
}
template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType>& x) {
  using pairtype = std::pair<KeyType, ValueType>;
  return *std::max_element(x.begin(), x.end(),
                           [](const pairtype& p1, const pairtype& p2) {
                             return p1.second < p2.second;
                           });
}
static inline bool isvowel(char ch) {
  static const std::string vowels("aeiouEAIOU");
  return vowels.end() != std::find(vowels.begin(), vowels.end(), ch);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<char>> v(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> v[i][j];
  }
  int c = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0, cnt1 = 0;
    for (int j = 0; j < n; ++j) {
      if (v[i][j] == 'C') cnt++;
      if (v[j][i] == 'C') cnt1++;
    }
    c += (cnt * (cnt - 1)) / 2;
    c += (cnt1 * (cnt1 - 1)) / 2;
  }
  cout << c << endl;
  return 0;
}
