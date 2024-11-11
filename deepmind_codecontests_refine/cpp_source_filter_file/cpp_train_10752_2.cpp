#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  os << "(" << p.first << "," << p.second << ") ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto i : v) os << i << " ";
  return os;
}
template <typename T>
void p_a(T a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
long long int first[2 * (long long int)2e5 + 10];
long long int f(long long int a[], long long int n, long long int c,
                long long int d) {
  for (long long int i = 0; i < 2 * n + 10; i++) first[i] = n;
  first[n] = -1;
  long long int sum = 0;
  long long int res = 0;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    if (a[i] == c)
      x = -1;
    else if (a[i] == d)
      x = 1;
    else
      x = 0;
    sum += x;
    long long int r = sum + 100;
    if (first[r] != n) {
      res = max(res, i - first[r]);
    }
    first[r] = min(first[r], i);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n;
  cin >> n;
  long long int a[n];
  long long int c[101] = {};
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) {
    c[a[i]]++;
  }
  long long int mxi = 0;
  for (long long int i = 0; i <= 100; i++) {
    if (c[mxi] < c[i]) {
      mxi = i;
    }
  }
  long long int res = 0;
  for (long long int i = 0; i <= 100; i++) {
    if (i == mxi) continue;
    if (c[i]) {
      res = max(res, f(a, n, mxi, i));
    }
  }
  cout << res;
}
