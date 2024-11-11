#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> v) {
  for (long long int i = 0; i < (v.size()); ++i) cout << v[i] << " ";
  cout << "\n";
}
void show(int a[], int arraysize) {
  for (int i = 0; i < arraysize; ++i) cout << a[i] << " ";
  cout << "\n";
}
void show(unordered_set<int> s) {
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}
void show(unordered_map<int, int> make_pair) {
  for (auto it = make_pair.begin(); it != make_pair.end(); it++) {
    cout << it->first << " " << it->second << "\n";
  }
  cout << "\n";
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  long long int t, a, b, q, l, r, nl, cl, cr, nr;
  cin >> t;
  while (t) {
    cin >> a >> b >> q;
    if (a > b) swap(a, b);
    long long int lm = lcm(a, b);
    for (long long int i = 0; i < (q); ++i) {
      cin >> l >> r;
      l--;
      nl = l / lm;
      nr = r / lm;
      cl = nl * b;
      cr = nr * b;
      for (long long int j = 0; j < (b); ++j) {
        if (lm * nl + j <= l) cl++;
        if (lm * nr + j <= r) cr++;
      }
      cout << r - l - cr + cl << " ";
    }
    cout << "\n";
    t--;
  }
  return 0;
}
