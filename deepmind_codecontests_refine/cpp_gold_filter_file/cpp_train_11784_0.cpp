#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  multiset<int> q;
  int add;
  long long res = 0;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> add;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    q.insert(c[i]);
    while (!q.empty() && k < a[i]) {
      k += add;
      res += *q.begin();
      q.erase(q.begin());
    }
    if (k < a[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << res << "\n";
}
