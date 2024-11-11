#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e18, oo = 1e12 + 21;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, rad = 180 / acos(-1);
const ll mod = 1e9 + 7, N = 1e6 + 5, M = 5005;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<ll> v(3);
  cin >> v[0] >> v[1] >> v[2];
  do {
    if ((v[0] % 3) == 2 && (v[1] % 3) == 2 && (v[2] % 3) == 0 && v[2] > 1) {
      return cout << 3 + v[0] / 3 + v[1] / 3 + (v[2] - 3) / 3 << '\n', 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  do {
    if ((v[0] % 3) == 2 && (v[1] % 3) == 2 && (v[2] % 3) == 2) {
      return cout << 3 + v[0] / 3 + v[1] / 3 + v[2] / 3 << '\n', 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  do {
    if ((v[0] % 3) == 2 && (v[1] % 3) == 2 && v[2] > 1) {
      return cout << 3 + v[0] / 3 + v[1] / 3 + (v[2] - 2) / 3 << '\n', 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << v[0] / 3 + v[1] / 3 + v[2] / 3 + min({v[0] % 3, v[1] % 3, v[2] % 3})
       << '\n';
}
