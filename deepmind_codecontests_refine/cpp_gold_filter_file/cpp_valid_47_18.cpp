#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> v;
  long long x, y;
  cout << "and " << 1 << " " << 2 << "\n";
  cout.flush();
  cin >> x;
  cout << "or " << 1 << " " << 2 << "\n";
  cout.flush();
  cin >> y;
  long long r1 = x + y;
  cout << "and " << 1 << " " << 3 << "\n";
  cout.flush();
  cin >> x;
  cout << "or " << 1 << " " << 3 << "\n";
  cout.flush();
  cin >> y;
  long long r2 = x + y;
  cout << "and " << 2 << " " << 3 << "\n";
  cout.flush();
  cin >> x;
  cout << "or " << 2 << " " << 3 << "\n";
  cout.flush();
  cin >> y;
  long long r3 = x + y;
  long long a = (r1 + r2 - r3) / 2;
  long long b = r1 - a;
  long long c = r2 - a;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  for (int i = 4; i <= n; i++) {
    cout << "and " << 1 << " " << i << "\n";
    cout.flush();
    cin >> x;
    cout << "or " << 1 << " " << i << "\n";
    cout.flush();
    cin >> y;
    long long z = x + y;
    v.push_back(z - a);
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << "\n";
  cout.flush();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
