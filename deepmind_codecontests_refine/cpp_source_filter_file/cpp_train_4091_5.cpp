#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    long long W = 0;
    cin >> n >> W;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<int> answerIndex;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] < (W + 1) / 2) {
        sum += v[i];
        answerIndex.push_back(i);
        if (sum >= (W + 1) / 2) {
          cout << answerIndex.size() << "\n";
          for (auto x : answerIndex) {
            cout << x + 1 << " ";
          }
          cout << "\n";
          n = -1;
        }
      } else if (v[i] <= W) {
        cout << 1 << "\n";
        cout << i + 1 << "\n";
        n = -1;
      }
    }
    if (n == -1) {
      continue;
    }
    cout << -1 << "\n";
  }
}
