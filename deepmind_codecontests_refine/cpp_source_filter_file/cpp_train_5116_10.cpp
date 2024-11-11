#include <bits/stdc++.h>
using namespace std;
int a[1005];
int h;
vector<int> v;
bool chec(int x) {
  v.clear();
  for (int i = 0; i < x; i++) v.push_back(a[i]);
  sort(v.begin(), v.end());
  int p = h;
  for (int i = v.size() - 1; i >= 0; i -= 2) p -= v[i];
  return (p >= 0);
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n >> h;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1;
  int r = n + 1;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (chec(m))
      l = m;
    else
      r = m;
  }
  cout << l << endl;
}
