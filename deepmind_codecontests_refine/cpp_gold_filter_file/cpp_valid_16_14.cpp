#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MAX_SIZE = 100001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);
int getSetBitsFromOneToN(int N) {
  int two = 2, ans = 0;
  int n = N;
  while (n) {
    ans += (N / two) * (two >> 1);
    if ((N & (two - 1)) > (two >> 1) - 1)
      ans += (N & (two - 1)) - (two >> 1) + 1;
    two <<= 1;
    n >>= 1;
  }
  return ans;
}
void manipulated_seive(int N) {
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      SPF[i] = i;
    }
    for (long long int j = 0;
         j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
      isprime[i * prime[j]] = false;
      SPF[i * prime[j]] = prime[j];
    }
  }
}
long long digsum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
void zfunction(string s, string pattern, int z[]) {
  string f = pattern + '$' + s;
  z[1 + s.length() + pattern.length()] = {0};
  z[0] = 0;
  long long n = 1 + s.length() + pattern.length();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - 1]);
    }
    while (i + z[i] < n and f[z[i]] == f[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool find_any_solution(int a, int b, int c, int& x0, int& y0, int& g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
int PermutationCoeff(int n, int k) {
  int P = 1;
  for (int i = 0; i < k; i++) P *= (n - i);
  return P;
}
vector<string> split(const string& str, char delim) {
  vector<string> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(str.substr(start, end - start));
  }
  return strings;
}
vector<int> splitStringToInt(const string& str, char delim) {
  vector<int> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(stoi(str.substr(start, end - start)));
  }
  return strings;
}
void printVector(vector<int> vec) {
  for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}
void printVector(vector<string> vec) {
  for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}
int countDivisors(long long n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int nextprime() { return prime.back(); }
int LCSubStr(string X, string Y, int m, int n) {
  int LCSuff[m + 1][n + 1];
  int result = 0;
  LCSuff[0][0] = 0;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (i == 0 || j == 0)
        LCSuff[i][j] = 0;
      else if (X[i - 1] == Y[j - 1]) {
        LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
        result = max(result, LCSuff[i][j]);
      } else
        LCSuff[i][j] = 0;
    }
  }
  return result;
}
long long m = 1000000007;
bool perfectsquare(long long x) {
  long long y = sqrt(x);
  if (y * y == x)
    return true;
  else
    return false;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
string createPermutationofalphabetinlexicographicorder(long long i) {
  return (i == 0)
             ? ""
             : (createPermutationofalphabetinlexicographicorder((i - 1) / 26) +
                char((i - 1) % 26 + 'a'));
}
long long binexp(long long a, long long b) {
  if (b == 0) return 1;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    string b = s;
    sort(s.begin(), s.end());
    for (long long i = 0; i < n; i++) {
      if (s[i] != b[i]) ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
