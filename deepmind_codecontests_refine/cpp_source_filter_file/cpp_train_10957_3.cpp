#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      a[i] = c - 48;
    }
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      b[i] = c - 48;
    }
    vector<int> v;
    int l = 0, r = n - 1, f = 0, c = 0;
    for (int x = n - 1; x >= 0; x--) {
      if (!f && (a[r] == b[r - l]) || f && (a[r] != b[l - r])) {
        if (f)
          r++;
        else
          r--;
        continue;
      }
      if (!f && (a[l] == b[r - l]) || f && (a[l] != b[l - r])) {
        v.push_back(1);
      }
      v.push_back(abs(r - l) + 1);
      if (f)
        r++;
      else
        l++;
      c = 1 - c;
      f = 1 - f;
      swap(l, r);
    }
    cout << v.size() << " ";
    for (int x = 0; x < v.size(); x++) {
      cout << v[x] << ' ';
    }
    cout << "\n";
  }
  return 0;
}
