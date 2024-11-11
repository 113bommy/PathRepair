#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 10903;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int p = 0;
    int L = 0, R = n - 1;
    vector<int> vec;
    while (L <= R) {
      p++;
      if (L == R) {
        vec.push_back(a[L]);
      } else {
        vec.push_back(a[L]);
        vec.push_back(a[R]);
      }
      L++;
      R--;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
      cout << vec[i] << '\t';
    }
    cout << '\n';
  }
}
