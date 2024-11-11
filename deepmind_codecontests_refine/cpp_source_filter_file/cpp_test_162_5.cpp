#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
bool isPo2(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int toint(const string &s) {
  stringstream second;
  second << s;
  int x;
  second >> x;
  return x;
}
string tostring(int number) {
  stringstream second;
  second << number;
  return second.str();
}
long long xorUptoN(long long n) {
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  return 0;
}
long long modExpo(long long x, long long y, int p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_Inv(long long a, long long p) { return modExpo(a, p - 2, p); }
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
bool isPossible(long long k, vector<long long> arr) {
  int n = (int)arr.size();
  vector<long long> add(n);
  for (int i = n - 1; i >= 2; i--) {
    if (arr[i] + add[i] < k) return false;
    long long d = min(arr[i], arr[i] + add[i] - k) / 3;
    add[i - 1] += d;
    add[i - 2] += 2 * d;
  }
  if ((arr[0] + add[0] < k)) return false;
  if ((arr[1] + add[1]) < k) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long l = -1, r = 1000006;
    while (r - l > 1) {
      long long mid = l + (r - l) / 2;
      if (isPossible(mid, arr))
        l = mid;
      else
        r = mid;
    }
    cout << l << "\n";
  }
}
