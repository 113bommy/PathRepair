#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k += 1) {
    int n;
    cin >> n;
    int ans = 0, a;
    vector<int> zeroes[10], ones[10];
    for (int j = 0; j < 7; j += 1) {
      vector<int> zeroes, ones;
      for (int i = 1; i <= n; i += 1) {
        if (i & (1 << j)) {
          ones.push_back(i);
        } else {
          zeroes.push_back(i);
        }
      }
      if (zeroes.size() > 0 && ones.size() > 0) {
        cout << ones.size() << " " << zeroes.size() << " ";
        for (int i = 0; i < ones.size(); i += 1) {
          cout << ones[i] << " ";
        }
        for (int i = 0; i < zeroes.size(); i += 1) {
          cout << zeroes[i] << " ";
        }
        cout << endl;
        cin >> a;
        ans = max(ans, a);
      }
    }
    cout << "-1 " << ans << endl;
  }
}
