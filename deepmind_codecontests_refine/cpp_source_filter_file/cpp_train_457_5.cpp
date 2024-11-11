#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool isPowerOfTwo(long long n) { return (ceil(log2(n)) == floor(log2(n))); }
int ti[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout.precision(18);
  int n, l;
  cin >> n >> l;
  int a = 0;
  vector<int> v;
  for (long long i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = l; i <= v[n - 1]; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt = cnt + (v[j] / l);
    }
    a = max(a, cnt * l);
  }
  cout << a;
}
