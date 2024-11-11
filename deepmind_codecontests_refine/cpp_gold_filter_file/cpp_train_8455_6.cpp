#include <bits/stdc++.h>
using namespace std;
void fst() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int nxt() {
  int x;
  cin >> x;
  return x;
}
int nex_l() {
  long long x;
  cin >> x;
  return x;
}
int main() {
  fst();
  int tc;
  cin >> tc;
  while (tc--) {
    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ;
    vector<int> first(n + 1);
    for (int i = 0; i < n; i++) {
      first[a[i]]++;
    }
    int fl = 0;
    auto x = *max_element(first.begin(), first.end());
    if (x >= 3)
      fl = 1;
    else if (x == 2) {
      for (int i = 0; i < n - 1; i++) {
        if (first[a[i]] == 2 && a[i] != a[i + 1]) {
          fl = 1;
        } else if (a[i] == a[i + 1]) {
          i++;
        }
      }
    } else
      fl = 0;
    if (fl)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
