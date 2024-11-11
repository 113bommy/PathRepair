#include <bits/stdc++.h>
using namespace std;
void cout_vector(vector<int> v) {
  for (long long unsigned i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(int a, int b) {
  bool aend = 0;
  if (a % 2) a--, aend = 1;
  if (b % 2) b--;
  a /= 2;
  b /= 2;
  if (a == b) {
    if (aend) return 1;
    return 0;
  }
  if (a < b) return 1;
  return 0;
}
long long gcd(long long a, long long b) {
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
void solve() {
  long long x, s;
  cin >> x >> s;
  if (x > s) {
    cout << -1;
    return;
  }
  if (x == 0 && s == 0) {
    cout << 0;
    return;
  }
  long long a = (s - x) / 2;
  if ((a ^ (s - a)) == x) {
    if (a == 0 || s - a == 0) {
      cout << 1 << endl << s;
      return;
    }
    cout << 2 << endl << a << " " << s - a;
    return;
  }
  if ((s - x) % 2 == 0) {
    cout << 3 << endl << x << " " << (s - x) / 2 << " " << (s - x) / 2;
    return;
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
