#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long BINARY_SEARCH(long long dp[], long long n, long long key) {
  long long s = 1;
  long long e = n;
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (dp[mid] == key)
      return mid;
    else if (dp[mid] > key)
      e = mid - 1;
    else
      s = mid + 1;
  }
  return -1;
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
long long STOI(string s) {
  long long num = 0;
  long long po = 1;
  for (long long i = s.length() - 1; i >= 0; i--) {
    num += po * (s[i] - '0');
    po *= 10;
  }
  return num;
}
long long modInverse(long long a, long long m) { return power(a, m - 2); }
int findLongestSub(string bin) {
  int n = bin.length(), i;
  int sum = 0;
  unordered_map<int, int> prevSum;
  int maxlen = 0;
  int currlen;
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
vector<long long> prefix_KMP(string &s) {
  vector<long long> pi;
  pi[0] = 0;
  for (long long i = 1; i <= s.length() - 1; i++) {
    long long j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ax, ay;
  cin >> ax >> ay;
  long long bx, by;
  cin >> bx >> by;
  long long cx, cy;
  cin >> cx >> cy;
  if (bx < ax && by < ay && cx < ax && cy < ay) {
    cout << "YES";
  } else if (bx > ax && by < ay && cx > ax && cy < ay) {
    cout << "YES";
  } else if (bx < ax && by > ay && cx < ax && cy > ay) {
    cout << "YES";
  } else if (bx > ax && by > ay && cx > ay && cy > ay) {
    cout << "YES";
  } else
    cout << "NO";
}
