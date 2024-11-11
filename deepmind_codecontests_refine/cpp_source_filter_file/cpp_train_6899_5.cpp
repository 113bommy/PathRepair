#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long temp = 0, flag = 0, diff = 0, sum = 0, result = 0, ct = 0,
              cnt = 0, found = 0;
    long long a = 0, b = 0, c = 0, n = 0, m = 0, k = 0, x = 0, y = 0;
    set<long long> s1;
    map<long long, long long> mapp;
    std::vector<long long> v, v1, v2;
    string s;
    cin >> s;
    string ss = s;
    reverse(ss.begin(), ss.end());
    if (s == ss) {
      cout << 0 << '\n';
      continue;
    }
    n = (long long)(s).size();
    cout << 4 << '\n';
    cout << "L " << 2 << '\n';
    n += (n - 2);
    cout << "R " << n - 1 << '\n';
    n += 1;
    cout << "R " << 2 << '\n';
    n += (n - 2);
    cout << "R " << n - 1 << '\n';
    cout << '\n';
  }
  return 0;
}
