#include <bits/stdc++.h>
using namespace std;
const int NN = 1e6 + 7;
const int N = 1e6 + 7;
const int M = 33;
const int mod = 1e9 + 7;
const long long inf = 1e18 + 7;
int n;
int a[N];
void solve1() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int bit = 1; bit <= 25; bit += 1) {
    vector<int> v;
    for (int i = 1; i <= n; i += 1) {
      v.push_back((a[i] % (1 << bit)));
    }
    int cnt = 0;
    sort(v.begin(), v.end());
    int l1 = (1 << (bit - 1));
    int r1 = (1 << bit) - 1;
    int l2 = (1 << bit) + (1 << (bit - 1));
    int r2 = (1 << (bit + 1));
    for (int i = 0; i < n - 1; i += 1) {
      int l = i + 1, r = n - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (v[m] + v[i] >= l1)
          r = m;
        else
          l = m + 1;
      }
      int c1 = l;
      l = i + 1, r = n - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (v[m + 1] + v[i] > r1)
          r = m;
        else
          l = m + 1;
      }
      int c2 = l;
      l = i + 1, r = n - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (v[m] + v[i] >= l2)
          r = m;
        else
          l = m + 1;
      }
      int c3 = l;
      l = n - 1;
      if (c2 >= c1 && v[c2] + v[i] >= l1 && v[c2] + v[i] <= r1)
        cnt += c2 - c1 + 1;
      if (l >= c3 && v[l] + v[i] >= l2 && v[l] + v[i] <= r2) cnt += l - c3 + 1;
    }
    if (cnt % 2) ans |= (1 << (bit - 1));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int cghf = 1;
  while (cghf--) {
    solve1();
  }
}
