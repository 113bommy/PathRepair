#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
long long powermod(long long a, long long b, long long modi) {
  a %= modi;
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % modi;
    }
    b /= 2;
    a = (a * a) % modi;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binarySearch(long long a[], long long low, long long high,
                       long long key) {
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (a[mid] < key) {
      low = mid + 1;
    } else if (a[mid] > key) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long binarytodecimal(string n) {
  string num = n;
  long long dec_value = 0;
  long long base = 1;
  long long len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
string dtb(long long n) {
  string s = "";
  while (n > 0) {
    if (n % 2 == 0)
      s.push_back('0');
    else
      s.push_back('1');
    n /= 2;
  }
  reverse((s).begin(), (s).end());
  return s;
}
vector<long long> seive;
void Seive() {
  const long long maxn = 1e6 + 5;
  seive.resize(maxn);
  for (long long i = (long long)0; i < (long long)maxn; i++) seive[i] = i;
  for (long long i = 2; i <= maxn; i += 2) seive[i] = 2;
  seive[1] = -1;
  seive[0] = -1;
  for (long long i = 3; i <= maxn; i += 2)
    if (i == seive[i])
      for (long long j = i * i; j < maxn; j += i)
        if (seive[j] == j) seive[j] = i;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  int a[n];
  for (long long i = (long long)0; i < (long long)n; i++) {
    cin >> a[i];
  }
  int b[m];
  for (long long i = (long long)0; i < (long long)m; i++) {
    cin >> b[i];
  }
  long long i = 0, j = 0;
  long long s1 = 0, s2 = 0;
  s1 = a[0];
  s2 = b[0];
  long long count = 0;
  int k = 100;
  while (i != n && j != m) {
    if (s1 == s2) {
      count++;
      i++;
      j++;
      if (i < n) {
        s1 = a[i];
      }
      if (j < m) {
        s2 = b[j];
      }
    } else if (s1 > s2) {
      j++;
      if (j < m) {
        s2 += b[j];
      }
    } else {
      i++;
      if (i < n) {
        s1 += a[i];
      }
    }
  }
  cout << count << '\n';
  return 0;
}
