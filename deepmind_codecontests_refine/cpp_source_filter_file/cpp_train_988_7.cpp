#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e8;
const long long OOL = 1e16;
const long long MOD = 1e9 + 7;
const double EPS = 1e-9;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return (b == 0 ? a : gcd(b, a % b));
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return (a * (b / gcd(a, b)));
}
long long N, K;
void printVec(vector<int> v2) {
  for (int i = 0; i < (int)v2.size(); ++i) cout << v2[i] << " ";
  cout << endl;
}
int main() {
  long long x = 0, y = 0;
  vector<int> v;
  int l, r;
  cin >> l >> r;
  char c;
  long long p = 0;
  for (int i = 0; i < l; i++) {
    cin >> N;
    v.push_back(N);
  }
  int pw = 1;
  x += v[v.size() - 1];
  for (int i = v.size() - 2; i >= 0; i--) {
    pw *= r;
    x += v[i] * pw;
  }
  v.clear();
  cin >> l >> r;
  for (int i = 0; i < l; i++) {
    cin >> N;
    v.push_back(N);
  }
  pw = 1;
  y += v[v.size() - 1];
  for (int i = v.size() - 2; i >= 0; i--) {
    pw *= r;
    y += v[i] * pw;
  }
  if (x == y)
    cout << "=";
  else if (x > y)
    cout << ">";
  else
    cout << "<";
  return 0;
}
