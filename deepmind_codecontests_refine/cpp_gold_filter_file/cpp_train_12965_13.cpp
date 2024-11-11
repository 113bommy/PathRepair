#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long getsum(string n) {
  long long ans = 0;
  for (long long i = 0; i < n.length(); i++) {
    ans += n[i] - '0';
  }
  return ans;
}
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
string CONVERT_TO_BINARY(long long s) {
  string res = "";
  while (s != 0) {
    res += (char)('0' + s % 2);
    s /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
bool PALIN(string s) {
  long long i = 0;
  long long j = s.length() - 1;
  while (i <= j) {
    if (s[i] != s[j]) return false;
    j--, i++;
  }
  return true;
}
long long modInverse(long long a, long long m) { return power(a, m - 2); }
long long findLongestSub(string bin) {
  long long n = bin.length(), i;
  long long sum = 0;
  unordered_map<long long, long long> prevSum;
  long long maxlen = 0;
  long long currlen;
  for (i = 0; i < n; i++) {
    if (bin[i] == '1')
      sum++;
    else
      sum--;
    if (sum > 0) {
      maxlen = i + 1;
    } else if (sum <= 0) {
      if (prevSum.find(sum - 1) != prevSum.end()) {
        currlen = i - prevSum[sum - 1];
        maxlen = max(maxlen, currlen);
      }
    }
    if (prevSum.find(sum) == prevSum.end()) prevSum[sum] = i;
  }
  return maxlen;
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  long long base = 1;
  long long len = num.length();
  for (long long i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
long long _gcd(long long a, long long b) {
  if (b > a) return _gcd(b, a);
  if (b == 0)
    return a;
  else
    return _gcd(b, a % b);
}
long long digitsum(long long num) {
  long long ans = 0;
  while (num > 0) {
    ans += num % 10;
    num /= 10;
  }
  return ans;
}
long long countbits(long long n) {
  long long cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 2;
  }
  return cnt;
}
void _ios() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(0);
  cout.tie(0);
}
void _rw() {}
bool *isprime = new bool[105]{false};
vector<long long> v;
void sieve() {
  isprime[0] = true;
  isprime[1] = true;
  for (long long i = 2; i * i < 105; i++) {
    if (isprime[i] == false) {
      for (long long j = i * 2; j < 105; j += i) {
        isprime[j] = true;
      }
    }
  }
  for (long long i = 0; i <= 100; i++) {
    if (isprime[i] == false) v.push_back(i);
  }
}
int main() {
  long long cnt = 0;
  long long i = 0;
  sieve();
  while (1) {
    if (v[i] > 50) break;
    cout << v[i] << '\n';
    fflush(stdout);
    string q;
    cin >> q;
    if (q == "yes") cnt++;
    if (cnt == 2) {
      cout << "composite" << '\n';
      return 0;
    }
    if (v[i] * v[i] < 100) {
      cout << v[i] * v[i++] << '\n';
      fflush(stdout);
      string q;
      cin >> q;
      if (q == "yes") cnt++;
      if (cnt == 2) {
        cout << "composite" << '\n';
        return 0;
      }
    } else
      i++;
  }
  cout << "prime" << '\n';
  return 0;
}
