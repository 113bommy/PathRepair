#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second < b.second) return true;
  if (a.second == b.second) return a.first < b.first;
  return false;
}
bool isprime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int ncr(long long int n, long long int r) {
  if (r == 0) return 1;
  r = min(r, n - r);
  long long int ans = 1;
  for (int i = 1; i <= r; i++) {
    ans *= (n - i + 1);
    ans /= i;
  }
  return ans;
}
int pare[150005], ocu[150005];
int fin(int x) {
  if (pare[x] == x)
    return x;
  else
    return pare[x] = fin(pare[x]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 150005; i++) pare[i] = i;
  for (int i = 0; i < 150005; i++) ocu[i] = 0;
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    char c = 'A', d = 'a';
    vector<string> v(n - k + 1), ans(n);
    int x = n - k + 1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int p = 0;
    string s = "";
    while (p < n) {
      s = "";
      s += c;
      s += d;
      if (d == 'z') {
        c++;
        d = 'a';
      } else
        d++;
      ans[p] = s;
      p++;
    }
    for (int i = 0; i < n - k + 1; i++) {
      if (v[i] == "NO") {
        ans[i + k - 1] = ans[i];
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
  }
  return 0;
}
