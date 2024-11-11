#include <bits/stdc++.h>
using namespace std;
int T;
vector<long long> v;
long long factorial(long long x) {
  long long total = 1;
  for (int i = 2; i <= x; i++) total *= i;
  return total;
}
bool isprime(long long x) {
  vector<bool> prime(x + 1, 1);
  prime[0] = prime[1] = 0;
  for (long long i = 2; i * i <= x; i++)
    if (prime[i])
      for (long long j = i * i; j <= x; j += i) prime[j] = 0;
  return prime[x];
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long temp = 1;
long long fastpow(long long base, long long exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return (temp * base);
  if (exponent % 2 == 0)
    return fastpow(base * base, exponent / 2);
  else {
    temp *= base;
    fastpow(base * base, exponent / 2);
  }
}
void fill(long long f) {
  v.clear();
  long long x;
  for (long long i = 0; i < f; i++) {
    cin >> x;
    v.push_back(x);
  }
}
void printv() {
  int size = v.size() - 1;
  for (int i = 0; i <= size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
bool is = 0;
long long f(long long n) {
  long long num = n;
  long long Max = 0, Min = 9;
  while (n) {
    long long dig = n % 10;
    if (dig == 0) {
      is = 1;
      return num;
    }
    Max = max(Max, dig);
    Min = min(Min, dig);
    n /= 10;
  }
  return Max * Min + num;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<string> > arr(n, vector<string>(m));
  map<string, int> fr;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == "10" || arr[i][j] == "01") arr[i][j] = "10";
      fr[arr[i][j]]++;
    }
  int cn = fr["11"] % m;
  int left = m - cn;
  if (fr["10"] % 2 == 0) {
    fr["10"] = fr["10"] / 2;
    fr["01"] = fr["10"];
  } else {
    fr["10"] = fr["10"] / 2 + 1;
    fr["01"] = fr["10"] - 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (fr["11"]) {
        cout << 11 << " ";
        fr["11"]--;
      } else if (fr["00"] && (left == 0 || left == m)) {
        cout << "00"
             << " ";
        fr["00"]--;
      } else if (fr["10"]) {
        cout << 10 << " ";
        fr["10"]--;
        left--;
      } else if (fr["01"]) {
        cout << "01"
             << " ";
        fr["01"]--;
      }
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
