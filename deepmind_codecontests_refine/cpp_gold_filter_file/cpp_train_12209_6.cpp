#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
int a[MAXN];
int b[MAXN];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, T;
    cin >> n >> T;
    unordered_map<int, int> Hash;
    unordered_map<int, int> c, d;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (Hash[T - a[i]] != 0) {
        if (c[T - a[i]] < d[T - a[i]]) {
          c[a[i]]++;
          b[i] = 1;
        } else {
          d[a[i]]++;
          b[i] = 0;
        }
      } else {
        b[i] = 1;
        c[a[i]]++;
      }
      Hash[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
