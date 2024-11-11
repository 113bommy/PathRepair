#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> ops;
    for (int i = 0; i < n - 2; ++i) {
      if (a[i] == 0) {
        continue;
      }
      int j = i + 1;
      while (j < n and a[j] == 1) {
        ++j;
      }
      int sz = j - i;
      if (sz % 2 == 0 or j + 1 >= n) {
        i = j;
      } else if (a[j + 1] == 0) {
        ops.push_back(j - 1);
        a[j] = a[j + 1] = 1;
        i = j;
      } else {
        ops.push_back(j - 1);
        a[j - 1] = a[j + 1] = 0;
        i = j;
      }
    }
    for (int i = 0; i < n - 2; ++i) {
      if (a[i] + a[i + 1] + a[i + 2] == 2) {
        ops.push_back(i);
        a[i] = a[i + 1] = a[i + 2] = 0;
      }
    }
    for (int i = n - 1; i >= 2; --i) {
      if (a[i] + a[i - 1] + a[i - 2] == 2) {
        ops.push_back(i - 2);
        a[i] = a[i - 1] = a[i - 2] = 0;
      }
    }
    if (count(a.begin(), a.end(), 1)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ops.size() << '\n';
      for (auto& i : ops) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
    }
  }
}
