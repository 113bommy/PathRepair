#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> h;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h.insert(a[i]);
  }
  if (int(h.size()) <= n - 2) {
    cout << "cslnb\n";
    return 0;
  }
  sort(a.begin(), a.end());
  bool win = true;
  if (h.size() == n - 1) {
    int i = 0;
    while (a[i] != a[i + 1]) i++;
    if (h.count(a[i] - 1)) {
      cout << "cslnb\n";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int take = a[i] - i;
    if (take < 0) {
      cout << "cslnb\n";
      return 0;
    }
    take %= 2;
    if (take) win = !win;
  }
  if (!win) {
    cout << "sjfnb\n";
  } else {
    cout << "cslnb\n";
  }
}
