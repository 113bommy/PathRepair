#include <bits/stdc++.h>
using namespace std;
void FastInputOutput() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
string toBinary(long long n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
string ToString(unsigned long long i) {
  ostringstream oss;
  oss << i;
  return oss.str();
}
string remove_char(string str, char ch) {
  str.erase(remove(str.begin(), str.end(), ch), str.end());
  return str;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int minSum(int arr[], int n, int k) {
  int res = 0, id = 0;
  int maxx = INT_MAX;
  for (int i = 0; i < n - k; i++) {
    for (int j = i; j < i + k; j++) {
      res += arr[j];
    }
    if (res < maxx) {
      maxx = res;
      id = i + 1;
    }
    res = 0;
  }
  int curr_sum = res;
  for (int i = k; i < n; i++) {
    curr_sum += arr[i] - arr[i - k];
    res = min(res, curr_sum);
    id = i;
  }
  return id + 1;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
string LETTRES = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", cons = "bcdfghjklmnpqrstvxzt",
       vowel = "aoyeui";
void sieve(long long n) {
  bool prime[28800];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * 2; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
}
int f(long long num) {
  long long sum = 0;
  while (num != 0) {
    sum = sum + num % 10;
    num = num / 10;
  }
  return sum;
}
int main() {
  FastInputOutput();
  long long n, m;
  cin >> n >> m;
  long long t[n];
  long long f[10] = {0};
  for (long long i = 0; i < n; i++) cin >> t[i];
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    f[x] = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (f[t[i]] != 0) cout << t[i] << ' ';
  }
}
