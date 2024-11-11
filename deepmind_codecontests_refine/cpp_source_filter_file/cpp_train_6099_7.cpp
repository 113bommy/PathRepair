#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pow(long long n, long long e) {
  if (e == 0)
    return 1;
  else if (e == 1)
    return n;
  else if (e % 2 == 0)
    return pow(n, e / 2);
  else
    return pow(n, e / 2) * n;
}
bool prime(long long n) {
  long long ct = 0;
  for (long long i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int solve() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  ;
  long long n, temp, mi, q, ma = 0;
  string s;
  string t;
  getline(cin, s);
  getline(cin, t);
  n = s.length();
  int a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long mid, start = 0, end = n - 1;
  bool flag = true;
  long long res = 0;
  while (start <= end) {
    flag = true;
    mid = (start + end) / 2;
    char c[n];
    fill(c, c + n, '$');
    for (long long i = mid + 1; i < n; i++) c[a[i] - 1] = s[a[i] - 1];
    int pos = 0;
    for (long long i = 0; i < n; i++) {
      if (pos == t.length()) break;
      if (c[i] == t[pos]) pos++;
    }
    if (pos == t.length()) {
      res = max(res, mid);
      flag = true;
    } else
      flag = false;
    if (flag)
      start = mid + 1;
    else
      end = mid - 1;
  }
  cout << res + 1;
  return 0;
}
int main() {
  clock_t start, end;
  start = clock();
  solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "Time taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec " << endl;
  return 0;
}
