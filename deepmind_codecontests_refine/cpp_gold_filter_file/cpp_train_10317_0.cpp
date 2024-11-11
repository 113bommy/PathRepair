#include <bits/stdc++.h>
using namespace std;
long long maxarr(vector<long long> &arr);
long long minarr(vector<long long> &arr);
long long gcd(long long a, long long b);
long long choose(long long n, long long k);
bool isprime(long long n);
void setprime(bool isprime[], long long n);
int main() {
  string str;
  cin >> str;
  long long n, dist = 0;
  scanf("%lld", &n);
  map<char, long long> num;
  map<long long, long long> hm;
  for (long long i = 0; i < str.length(); i++) {
    if (num.count(str[i]) == false) {
      num[str[i]] = 1;
      hm[1]++;
      dist++;
    } else {
      hm[num[str[i]]]--;
      num[str[i]]++;
      hm[num[str[i]]]++;
    }
  }
  if (str.length() <= n)
    cout << 0 << endl;
  else {
    long long i = 1;
    long long pos = 0;
    while (n > 0) {
      if (n >= i * hm[i]) {
        n = n - i * hm[i];
        dist = dist - hm[i];
        hm[i] = 0;
      } else {
        dist = dist - n / i;
        hm[i] = hm[i] - n / i;
        break;
      }
      i++;
    }
    cout << dist << endl;
    set<char> s;
    for (long long i = 0; i < str.length(); i++) {
      if (s.count(str[i]) == true)
        cout << str[i];
      else {
        if (hm[num[str[i]]] > 0) {
          cout << str[i];
          s.insert(str[i]);
          hm[num[str[i]]]--;
        }
      }
    }
  }
  return 0;
}
long long maxarr(vector<long long> &arr) {
  long long maxll = LONG_LONG_MIN;
  for (long long i = 0; i < arr.size(); i++) maxll = max(arr[i], maxll);
  return maxll;
}
long long minarr(vector<long long> &arr) {
  long long minll = LONG_LONG_MAX;
  for (long long i = 0; i < arr.size(); i++) minll = min(arr[i], minll);
  return minll;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long choose(long long n, long long k) {
  if (k == 0) return 1;
  return (n * choose(n - 1, k - 1)) / k;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void setprime(bool isprime[], long long n) {
  for (long long i = 0; i < n; i++) isprime[i] = true;
  isprime[0] = false;
  isprime[1] = false;
  for (long long i = 2; i < n; i++) {
    for (long long j = 2; i * j < n; j++) isprime[i * j] = false;
  }
}
