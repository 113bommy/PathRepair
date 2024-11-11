#include <bits/stdc++.h>
using namespace std;
const short inf = 1 << 14;
const double pi = acos(-1);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int mf[] = {0, 0, 1, -1}, mc[] = {1, -1, 0, 0};
const int N = 1005;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
static T randint(T lo, T hi) {
  return uniform_int_distribution<T>(lo, hi)(rng);
}
template <typename T>
static T randreal(T lo, T hi) {
  return uniform_real_distribution<T>(lo, hi)(rng);
}
int main() {
  rng.seed(time(0));
  vector<long long> a(4);
  cin >> a[1] >> a[2] >> a[3];
  vector<int> id(4);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return a[i] < a[j]; });
  cout << "First" << endl;
  long long y = a[id[3]] * 2ll - a[id[2]] - a[id[1]];
  cout << y << endl;
  int x;
  cin >> x;
  if (x == 0) return 0;
  if (x == id[1]) {
    y = a[id[3]] - a[id[2]];
    cout << y << endl;
    cin >> x;
    assert(x == 0);
    return 0;
  }
  if (x == id[2]) {
    y = a[id[3]] - a[id[1]];
    cout << y << endl;
    cin >> x;
    assert(x == 0);
    return 0;
  }
  a[3] += y;
  y = a[id[3]] * 2ll - a[id[2]] - a[id[1]];
  cout << y << endl;
  cin >> x;
  if (x == 0) return 0;
  if (x == id[1]) {
    y = a[id[3]] - a[id[2]];
    cout << y << endl;
    cin >> x;
    assert(x == 0);
    return 0;
  }
  if (x == id[2]) {
    y = a[id[3]] - a[id[1]];
    cout << y << endl;
    cin >> x;
    assert(x == 0);
    return 0;
  }
  assert(false);
  return 0;
}
