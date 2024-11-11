#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long i = n - 2; i >= 0; i--) {
    long long a = v[i].size();
    long long b = v[i + 1].size();
    long long j = 0;
    string sta = v[i];
    string stb = v[i + 1];
    bool checksmall = false;
    for (j = 0; j < min(a, b); j++) {
      if (sta[j] > stb[j]) {
        break;
      }
      if (sta[j] < stb[j]) {
        checksmall = true;
        break;
      }
    }
    if (checksmall) continue;
    v[i].erase(j, 6 * 1e5);
  }
  for (long long i = 0; i < n; i++) {
    cout << v[i] << "\n";
  }
  return 0;
}
