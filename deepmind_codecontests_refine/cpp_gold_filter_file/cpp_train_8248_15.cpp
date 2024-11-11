#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
X:
  while (t--) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    std::vector<int> ara(1025, 0);
    int mx = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      mx = max(x, mx);
      ara[x]++;
    }
    for (int i = 1; i <= 1024; i++) {
      int c = 0;
      std::vector<int> ara2;
      ara2 = ara;
      for (auto x : v) {
        int temp = x ^ i;
        if (temp > mx) {
          break;
        } else {
          if (ara[temp] == 0) {
            break;
          } else {
            c++;
            if (temp != x) {
              ara2[x]--;
              ara2[temp]++;
            }
          }
        }
      }
      if (c == n) {
        cout << i << endl;
        goto X;
      }
    }
    cout << -1 << endl;
  }
  return 0;
}
