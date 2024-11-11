#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using iii = tuple<int, int, int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m = 1, k = 1;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], --a[i];
  for (int i = 0; i < n; i++) {
    m = max(m, a[i]);
    if (i == m && a[i] == m) k++;
  }
  cout << k;
}
