#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
vector<int> g[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (n < 6 || k < (n + 1)) return puts("-1"), 0;
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (i == a || i == b || i == c || i == d) continue;
    v.push_back(i);
  }
  cout << a << " " << c << " ";
  for (auto i : v) cout << i << " ";
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (auto i : v) cout << i << " ";
  cout << b << " " << d;
}
