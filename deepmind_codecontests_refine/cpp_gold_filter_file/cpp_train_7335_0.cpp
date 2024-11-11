#include <bits/stdc++.h>
using namespace std;
void solve(int test_case) {
  int n;
  cin >> n;
  vector<int> f, s;
  long long num = 0;
  long long sumf = 0, sums = 0;
  for (int i = 1; i <= n; ++i) {
    long long a;
    cin >> a;
    if (i == n) num = a;
    if (a > 0) {
      f.push_back(a);
      sumf += a;
    } else {
      a = -a;
      s.push_back(a);
      sums += a;
    }
  }
  if (sumf > sums) {
    cout << "first\n";
  } else if (sums > sumf) {
    cout << "second\n";
  } else {
    int sz_f = f.size();
    int sz_s = s.size();
    int lim = min(sz_f, sz_s);
    for (int i = 0; i < lim; ++i) {
      if (f[i] == s[i])
        continue;
      else if (f[i] > s[i]) {
        cout << "first\n";
        return;
      } else {
        cout << "second\n";
        return;
      }
    }
    if (sz_f > sz_s) {
      cout << "first\n";
    } else if (sz_f < sz_s) {
      cout << "second\n";
    } else {
      if (num > 0) {
        cout << "first\n";
      } else {
        cout << "second\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int i = 1; i <= tc; ++i) {
    solve(i);
  }
  return 0;
}
