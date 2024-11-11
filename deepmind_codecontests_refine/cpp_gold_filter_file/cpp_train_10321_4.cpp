#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod) { return mt() % mod; }
int gcd(int x, int y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    int temp = x % y;
    x = y;
    y = temp;
    if (x < y) swap(x, y);
  }
  return x;
}
int main() {
  int n;
  cin >> n;
  int li = 0, ri = 1e9;
  int maxv = 0;
  while (li < ri) {
    int mid = (li + ri) / 2;
    bool answ;
    cout << "> " << mid << endl;
    cin >> answ;
    if (answ) {
      li = mid + 1;
      maxv = max(maxv, mid + 1);
    } else {
      ri = mid;
    }
  }
  int x;
  vector<int> v;
  for (int i = 1; i <= 30; i++) {
    cout << "? " << myrand(n) + 1 << endl;
    cin >> x;
    v.push_back(maxv - x);
  }
  sort(v.begin(), v.end());
  int d = 0;
  for (int i = 0; i < 30; i++) {
    d = gcd(v[i], d);
  }
  cout << "! " << maxv - (n - 1) * d << " " << d << endl;
  return 0;
}
