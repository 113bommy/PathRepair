#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long fact(long long n) {
  long long ret = 1;
  for (int i = 1; i <= n; i++) ret *= i;
  return ret;
}
bool is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  return 0;
}
long double getDistance(long double x1, long double y1, long double x2,
                        long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
vector<int> p[1000005];
bool is[1000005];
void sieve() {
  for (int i = 2; i < N; i++) {
    if (is[i] == 0) {
      for (int j = i; j < N; j += i) is[j] = 1, p[j].push_back(i);
    }
  }
}
int main() {
  sieve();
  int n, mn;
  cin >> n;
  mn = n;
  for (int i = 0; i < p[n].size(); i++) {
    int cur = p[n][i];
    for (int j = n - cur + 1; j <= n; j++) {
      for (int k = 0; k < p[j].size(); k++) {
        if (j - p[j][k] < 3) continue;
        mn = min(mn, j - p[j][k] + 1);
      }
    }
  }
  cout << mn;
  return 0;
}
