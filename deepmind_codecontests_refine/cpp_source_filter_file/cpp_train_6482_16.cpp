#include <bits/stdc++.h>
using namespace std;
long long int t, n, cnt, win;
vector<long long int> a;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n, a.clear(), a.resize(n), cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; a[i] == 1 && i != n - 1; i++) {
      cnt++;
    }
    if (cnt & 1)
      cout << "second\n";
    else
      cout << "first\n";
  }
  return 0;
}
