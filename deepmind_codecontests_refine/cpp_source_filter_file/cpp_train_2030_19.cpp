#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
long long inv(long long x) { return expo(x, mod - 2); }
bool isPal(string ss) {
  int len = ss.length();
  for (int i = 0; i < len / 2; i++) {
    int comp = len - i - 1;
    if (ss[i] != ss[comp]) return false;
  }
  return true;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 1001;
int arr[M];
bool can[M];
int MM;
int n, m;
bool pre() {
  for (int i = 1; i < M; i++) {
    int val = arr[i];
    if (val == 0) continue;
    vector<int> vec;
    vec.push_back(0);
    for (int j = 1; j < M; j++) {
      if (can[j] == 1) vec.push_back(j);
    }
    for (int j = 0; j < vec.size(); j++) {
      int num = vec[j];
      for (int mul = 1; mul <= val; mul++) {
        int tt = mul * i;
        can[tt % m] = 1;
        can[(tt + num) % m] = 1;
        if (can[0] == 1) return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &(n));
  scanf("%d", &(m));
  for (int i = 0; i < n; i++) {
    long long el;
    scanf("%lld", &(el));
    int to = el % m;
    arr[to]++;
  }
  if (can[0] == 1) {
    cout << "YES";
    return 0;
  }
  if (pre()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
