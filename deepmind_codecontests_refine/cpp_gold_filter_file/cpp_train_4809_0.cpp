#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int e = 0; e < t; e++) {
    long long n;
    cin >> n;
    vector<bool> used(n + 2, false);
    long long q;
    long long last = -1;
    vector<long long> ans;
    long long index = 1;
    for (int i = 0; i < n; i++) {
      cin >> q;
      if (q != last) {
        ans.push_back(q);
        last = q;
        used[q] = true;
        continue;
      }
      while (used[index]) {
        index++;
        if (index >= q) {
          index = -1;
          break;
        }
      }
      if (index == -1) {
        cout << -1 << endl;
        while (i < n - 1) {
          cin >> q;
          i++;
        }
        break;
      }
      ans.push_back(index);
      used[index] = true;
      continue;
    }
    if (index != -1)
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
    cout << endl;
  }
}
