#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
const unsigned int MOD = 1000000007;
template <class T>
T power(T a, long long int n) {
  T res = 1;
  while (n > 0) {
    if (n % 2) res = (res * a);
    a = (a * a), n = n / 2;
  }
  return res;
}
unsigned int factorial(unsigned int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
bool isprime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
inline long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
inline long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<long long int, long long int> maps;
  long long int maxe = 0;
  long long int d = 0;
  long long int n, k, m;
  cin >> n >> k >> m;
  long long int temp = n;
  vector<long long int> arr;
  ;
  long long int a;
  while (temp--) {
    cin >> a;
    arr.push_back(a);
    maps[a % m]++;
    if (maps[a % m] > maxe) maxe = maps[a % m], d = a % m;
  }
  if (maxe < k)
    cout << "No";
  else {
    vector<long long int> ans;
    ;
    for (auto x : arr)
      if (x % m == d) ans.push_back(x);
    cout << "Yes" << endl;
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
  }
}
