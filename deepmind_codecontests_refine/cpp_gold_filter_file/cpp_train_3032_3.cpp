#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 8e18;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 300;
int n, t;
int p[N + 1];
vector<int> v;
string s;
int get(int l, int r) {
  int ans;
  cout << '?' << ' ' << l << ' ' << r << '\n';
  cin >> ans;
  cout << '?' << ' ' << l << ' ' << r << '\n';
  cin >> ans;
  return ans;
}
int getcnt(int a, int b, int t) {
  t -= b - a;
  t /= 2;
  return a - t;
}
int cnt1(int l, int r) {
  v.clear();
  for (int j = 0; j < 16; j++) {
    v.push_back(get(l, r));
  }
  sort((v).begin(), (v).end());
  int t, a, b;
  a = v[0];
  b = v[v.size() - 1];
  t = (n - r) + (l - 1);
  return getcnt(a, b, t);
}
int main() {
  cin >> n >> t;
  for (int i = n; i >= 1; i--) {
    p[i] = cnt1(1, i);
  }
  s += '0' + p[1];
  for (int i = 2; i <= n; i++) {
    s += '0' + (p[i] - p[i - 1]);
  }
  cout << '!' << ' ' << s << '\n';
  return 0;
}
