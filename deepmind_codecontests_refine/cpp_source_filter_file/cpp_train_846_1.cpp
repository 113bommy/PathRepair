#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int d = n - i;
    auto x = b.lower_bound(d);
    if (x == b.end()) x = b.begin();
    cout << (a[i] + *x) % n << " ";
    b.erase(x);
  }
}
