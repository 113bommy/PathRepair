#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    int s = 0;
    for (int i = n - 1; i > 0; --i)
      if (a[i] < a[i - 1]) s += a[i - 1] - a[i];
    cout << s << '\n';
  }
  return 0;
}
