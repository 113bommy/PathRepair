#include <bits/stdc++.h>
using namespace std;
vector<int> basis, vec;
void add(int val) {
  int temp = val;
  for (auto &v : basis) val = min(val, val ^ v);
  if (val > 0) {
    vec.push_back(temp);
    basis.push_back(val);
    for (int i = (int)basis.size() - 1; i > 0; --i) {
      if (basis[i] > basis[i - 1]) {
        swap(basis[i], basis[i - 1]);
      } else
        break;
    }
  }
}
const int N = 200000 + 7;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int x = 0;
  for (int i = 0, j = 0; i < 20; ++i) {
    for (; j < n and a[j] < (1 << i); ++j) {
      add(a[j]);
    }
    if (basis.size() == i) {
      x = i;
    }
  }
  vector<int> res(1, 0);
  for (int i = 0; i < x; ++i) {
    for (int j = res.size() - 1; j >= 0; --j) {
      res.push_back(res[j] ^ vec[i]);
    }
  }
  cout << x << "\n";
  for (auto qq : res) cout << qq << " ";
  cout << "\n";
  return 0;
}
