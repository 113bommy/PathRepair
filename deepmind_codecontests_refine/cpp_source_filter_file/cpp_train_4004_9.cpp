#include <bits/stdc++.h>
using namespace std;
inline bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
long long sumofdigit(long long n) {
  long long sum = 0;
  while (n) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd<T>(a, b);
}
template <class T>
inline T power(T b, T p) {
  long long ans = 1;
  while (p--) ans *= b;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  vector<long long> v;
  for (long long i = 1; i <= 75; i++) {
    long long x = b * pow(i, a) + c;
    if (sumofdigit(x) == i && x <= 1000000000 && x >= 0) v.push_back(x);
  }
  cout << v.size() << endl;
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
}
