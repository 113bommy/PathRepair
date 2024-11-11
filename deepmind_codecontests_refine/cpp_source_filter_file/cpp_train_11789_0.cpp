#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long N = 2e+5 + 7;
const long long MAXN = 1e+9;
const long long mod = 1e+9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> prince(n);
    vector<int> princess(n);
    vector<int> arr[n];
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int a;
        cin >> a;
        arr[i].push_back(a);
      }
      for (int el : arr[i]) {
        if (prince[el - 1] == 0) {
          prince[el - 1] = 1;
          princess[i] = 1;
          break;
        }
      }
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (prince[i] == 0) {
        p = i + 1;
        break;
      }
    }
    if (p == 0)
      cout << "OPTIMAL"
           << "\n";
    else {
      cout << "IMPROVE"
           << "\n";
      int d = 0;
      for (int i = 0; i < n; i++) {
        if (princess[i] == 0) {
          d = i + 1;
          break;
        }
      }
      cout << p << " " << d << "\n";
    }
  }
}
