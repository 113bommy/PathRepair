#include <bits/stdc++.h>
using namespace std;
template <typename T>
T pow(T a, T b, long long int m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
template <typename T>
T InverseMod(T a, long long int m) {
  return pow(a, m - 2, m);
}
template <typename T>
long long int SquareDist(T a, T b) {
  long long int x = abs(a.first - b.first), y = abs(a.second - b.second);
  return x * x + y * y;
}
const long long int s = 1e6;
void solve() {
  long long int n;
  cin >> n;
  multiset<long long int> ms;
  set<long long int> out;
  for (long long int i = 1; i <= n; ++i) {
    long long int temp;
    cin >> temp;
    ms.insert(temp);
  }
  long long int p = 1;
  map<long long int, long long int> mp;
  for (auto i : ms) {
    if (mp[i]) continue;
    if (ms.find(s + 1 - i) == ms.end()) {
      out.insert(s + 1 - i);
    } else {
      mp[s + 1 - i] = 1;
      while (ms.find(p) != ms.end() and ms.find(s + 1 - p) != ms.end()) {
        ++p;
      }
      out.insert(p);
      out.insert(s + 1 - p);
      ++p;
    }
  }
  cout << out.size() << '\n';
  for (auto i : out) {
    cout << i << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) solve();
}
