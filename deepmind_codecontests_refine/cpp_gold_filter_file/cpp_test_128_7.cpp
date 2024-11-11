#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  return a.second < b.second;
}
string bin(long long int n) {
  string s = "";
  while (n) {
    if (n % 2)
      s += '1';
    else
      s += '0';
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void Solve() {
  long long int n;
  cin >> n;
  long long int a, b, c;
  if ((n - 1) % 2) {
    c = 1;
    a = 2;
    b = n - 3;
    cout << a << " " << b << " " << c << '\n';
    return;
  }
  c = 1;
  long long int x = (n - 1) / 2;
  if (x % 2) {
    a = x - 2;
    b = x + 2;
  } else {
    a = x - 1;
    b = x + 1;
  }
  cout << a << " " << b << " " << c << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
