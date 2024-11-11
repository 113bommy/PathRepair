#include <bits/stdc++.h>
using namespace std;
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
map<char, bool> m;
string solve(string a, long long i, long long end, long long count, char prev) {
  if (i > end) return "";
  if (i == 0) prev = a[0];
  count++;
  if (m[a[i]] == true) {
    return a[i] + solve(a, i + 1, end, 0, prev);
  } else {
    if (count >= 3) {
      if (prev == a[i] && a[i] == a[i - 1]) {
        return a[i] + solve(a, i + 1, end, count, prev);
      } else {
        string ans = " ";
        ans += a[i];
        return ans + solve(a, i + 1, end, 1, a[i]);
      }
    } else
      return a[i] + solve(a, i + 1, end, count, prev);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a;
  cin >> a;
  m['a'] = true;
  m['e'] = true;
  m['i'] = true;
  m['o'] = true;
  m['u'] = true;
  cout << solve(a, 0, a.length() - 1, 0, '0') << '\n';
}
