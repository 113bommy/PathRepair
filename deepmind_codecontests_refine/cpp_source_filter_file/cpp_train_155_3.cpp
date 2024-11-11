#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 1e6 + 10;
long long dr[4] = {0, 0, 1, -1};
long long dc[4] = {1, -1, 0, 0};
long long ddr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long ddc[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long ddr1[8] = {1, 1, -1, -1, 2, 2, -2, -2};
long long ddc1[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int32_t main() {
  fast();
  long long n, k;
  cin >> n >> k;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<long long> v;
  v.emplace_back(a);
  v.emplace_back(c);
  for (long long i = 1; i < n + 1; i++) {
    if (i == a || i == b || i == c || i == d) continue;
    v.emplace_back(i);
  }
  v.emplace_back(d);
  v.emplace_back(b);
  if (k > n) {
    for (auto i : v) cout << i << " ";
    cout << "\n";
    swap(v[0], v[1]);
    swap(v[n - 1], v[n - 2]);
    for (auto i : v) cout << i << " ";
    cout << "\n";
  } else
    cout << "-1\n";
}
