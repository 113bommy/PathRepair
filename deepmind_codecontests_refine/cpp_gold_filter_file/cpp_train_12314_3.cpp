#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, t = 0;
    cin >> n;
    int A[n];
    unordered_set<int> uset;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
      if (uset.find(A[i]) != uset.end()) {
        cout << "YES" << endl;
        t++;
        break;
      } else
        uset.insert(A[i]);
    }
    if (t == 0) cout << "NO" << endl;
  }
}
