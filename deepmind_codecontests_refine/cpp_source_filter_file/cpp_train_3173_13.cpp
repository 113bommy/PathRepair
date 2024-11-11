#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
struct edge {
  int w, s;
};
bool cmp(const edge &a, const edge &b) { return a.w < b.w; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, d, a[123], mn = INT_MAX, mx = -1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  if (k >= mx) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < a[i] + 1; j++) cout << j << " ";
      cout << endl;
    }
  } else if (k + mn < mx)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (a[i] <= k) {
        for (int j = 1; j < k + 1; j++) cout << j << " ";
        cout << endl;
      } else {
        int di = a[i] / k;
        int dm = a[i] % k;
        for (int l = 0; l < di; l++) {
          for (int j = 1; j < k + 1; j++) cout << j << " ";
        }
        for (int j = 1; j < dm + 1; j++) cout << j << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
