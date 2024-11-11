#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
void amin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void amax(T& a, U b) {
  if (a < b) a = b;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  vector<long long> v(3);
  v[0] = a;
  v[1] = b;
  v[2] = c;
  (sort((v).begin(), (v).end()));
  a = v[0];
  b = v[1];
  c = v[2];
  long long ans = 0;
  for (long long i = 0; i < 3; i++)
    if (v[i] > 0) {
      ans++;
      v[i]--;
    }
  for (long long i = 0; i < 3; i++) {
    if (v[i] > 0 && v[(i + 1) % 3] > 0) {
      ans++;
      v[i]--;
      v[(i + 1) % 3]--;
    }
  }
  if (v[0] > 0 && v[1] > 0 && v[2] > 0) ans++;
  cout << ans << "\n";
}
void input() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  int i = 1;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
