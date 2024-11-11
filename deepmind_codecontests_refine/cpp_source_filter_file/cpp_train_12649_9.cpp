#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename T>
using vv = vector<vector<T>>;
long long base = 1e9 + 7;
long long st(int a) {
  long long res = 1;
  while (a) {
    res *= 10;
    --a;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> v;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (v.size() == 2) {
    cout << v[1] - v[0] << endl;
    return 0;
  }
  long long last = (n - 1) / 2;
  long long min = 1e10;
  long long s1 = 0;
  for (int i = 0; i < last; ++i) {
    s1 = -v[i] + v[i + v.size() - last - 1];
    if (s1 < min) {
      min = s1;
    }
  }
  cout << min << endl;
}
