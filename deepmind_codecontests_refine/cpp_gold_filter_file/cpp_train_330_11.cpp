#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, last, cnt = 0, g = 0, s = 0, b = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (v.size() != (n / 2 + 1)) v.push_back(a);
    }
    cnt = 1;
    int i = 0;
    while (i < v.size() - 1) {
      if (v[i + 1] != v[i]) {
        g = cnt;
        i++;
        break;
      } else
        cnt++;
      i++;
    }
    cnt = 1;
    while (i < v.size() - 1) {
      if (v[i + 1] != v[i]) {
        s += cnt;
        cnt = 1;
        if (s > g) {
          i++;
          break;
        }
      } else
        cnt++;
      i++;
    }
    cnt = 1;
    while (i < v.size() - 1) {
      if (v[i + 1] != v[i]) {
        b += cnt;
        cnt = 1;
      } else
        cnt++;
      i++;
    }
    if (g == 0 || s == 0 || b == 0 || g >= s || g >= b)
      cout << 0 << " " << 0 << " " << 0 << endl;
    else
      cout << g << " " << s << " " << b << endl;
  }
  return 0;
}
