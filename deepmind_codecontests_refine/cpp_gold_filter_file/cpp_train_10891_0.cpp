#include <bits/stdc++.h>
using namespace std;
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 4e5 + 3;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() {
  puts("Yes");
  exit(0);
}
void NO() {
  puts("NO");
  exit(0);
}
void No() {
  puts("No");
  exit(0);
}
void one() {
  puts("-1");
  exit(0);
}
int n;
int num1;
bool check(int le, int ri) {
  cout << "? ";
  string v;
  for (int i = 0; i < le; i++) v.push_back('0');
  for (int i = le; i <= ri; i++) v.push_back('1');
  for (int i = ri + 1; i < n; i++) v.push_back('0');
  cout << v << endl;
  int now;
  cin >> now;
  return (now < num1 + ri - le + 1) && (now > num1 - (ri - le + 1));
}
void solve() {
  cin >> n;
  string val(n, '0');
  cout << "? " << val << endl;
  fflush(stdout);
  cin >> num1;
  int le = 0;
  int ri = n - 1;
  while (ri - le > 1) {
    int mid = (le + ri) / 2;
    if (check(le, mid)) {
      ri = mid;
    } else {
      le = mid;
    }
  }
  cout << "? ";
  for (int i = 0; i < le; i++) cout << "0";
  for (int i = le; i < ri; i++) cout << "1";
  for (int i = ri; i < n; i++) cout << "0";
  cout << endl;
  fflush(stdout);
  int t;
  cin >> t;
  if (t > num1) {
    cout << "! " << le + 1 << " " << ri + 1 << endl;
  } else {
    cout << "! " << ri + 1 << " " << le + 1 << endl;
  }
}
int main() {
  solve();
  return 0;
}
