#include <bits/stdc++.h>
using namespace std;
void printprecise(double l, long long int precision) {
  std::cout << std::fixed;
  std::cout << std::setprecision(precision);
  std::cout << l;
}
long long int gcd(long long int a, long long int b) {
  if (a < b) {
    swap(a, b);
  }
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long int sti(string s) {
  long long int l = s.length();
  long long int n = 0;
  for (long long int i = 0; i < l; i++) {
    n = n * 10 + s[i] - '0';
  }
  return n;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  map<string, string> ma;
  string s, t;
  for (long long int i = 0; i < m; i++) {
    cin >> s >> t;
    ma[s] = (s.length() < t.length()) ? s : t;
  }
  for (long long int i = 0; i < n; i++) {
    cin >> s;
    cout << ma[s] << " ";
  }
  return 0;
}
