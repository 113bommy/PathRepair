#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int searchll(long long int val, vector<long long int> vec) {
  for (long long int i = 0; i < vec.size(); i++) {
    if (vec[i] == val) {
      return i;
    }
  }
  return -1;
}
bool isPrime(long long int n) {
  int broken = 0;
  for (long long int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) {
      broken = 1;
      break;
    }
  }
  if (broken == 1) {
    return false;
  } else {
    return true;
  }
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
vector<bool> SieveOfEratosthenes(long long int num) {
  vector<bool> pno;
  pno.assign(num + 1, true);
  pno[0] = false;
  pno[1] = false;
  for (long long int i = 2; i * i <= num; i++) {
    if (pno[i] == true) {
      for (long long int j = i * 2; j <= num; j += i) pno[j] = false;
    }
  }
  return pno;
}
vector<long long int> SieveOfEratosthenesExtended(long long int num) {
  vector<long long int> pno(num + 1);
  for (long long int i = 0; i < num + 1; i++) {
    pno[i] = i;
  }
  for (long long int i = 2; i * i <= num; i++) {
    if (pno[i] == i) {
      for (long long int j = i * 2; j <= num; j += i)
        if (pno[j] == j) pno[j] = i;
    }
  }
  return pno;
}
vector<long long int> PrimeFactorize(long long int num) {
  vector<long long int> spf;
  spf = SieveOfEratosthenesExtended(num);
  set<long long int> pf;
  while (num != 1) {
    pf.insert(spf[num]);
    num = num / spf[num];
  }
  vector<long long int> v;
  for (auto it : pf) {
    v.push_back(it);
  }
  return v;
}
long long int calculateNcR(long long int n, long long int r) {
  long long int p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long int m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}
long long int stringToInt(string s) {
  long long int num = 0;
  for (long long int i = 0; i < s.length(); i++) {
    num = num * 10 + (s[i] - '0');
  }
  return num;
}
vector<long long int> a;
long long int n;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  long long int maxLen = 0;
  set<long long int> elements;
  map<long long int, long long int> hash;
  for (long long int i = 0; i < n; i++) {
    elements.insert(a[i]);
  }
  long long int hashNum = 0;
  for (long long int num : elements) {
    hash[num] = hashNum;
    hashNum++;
  }
  for (long long int i = 0; i < n; i++) {
    a[i] = hash[a[i]];
  }
  vector<vector<long long int>> dp(n, vector<long long int>(n));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      dp[i][j] = 1;
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < i; j++) {
      dp[i][a[j]] =
          1 + dp[j][a[i]] > dp[i][a[j]] ? 1 + dp[j][a[i]] : dp[i][a[j]];
      if (dp[i][a[j]] > maxLen) {
        maxLen = dp[i][a[j]];
      }
    }
  }
  cout << maxLen << "\n";
}
