#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mx = 0;
  vector<int> q(n), q1;
  for (auto &i : q) {
    cin >> i;
    q1.push_back(i);
  }
  for (auto &i : q)
    if (i > mx) mx = i;
  vector<bool> used, used1;
  used.resize(n + 1);
  used1.resize(n + 1);
  int f;
  for (int i = 0; i < n; ++i) {
    used[q1[i]] = 1;
    if (q1[i] == mx) {
      f = q1[i];
      while (used[f] && f > 0) {
        cout << f << " ";
        used1[f] = 1;
        --f;
      }
    } else {
      if (used1[q1[i] + 1]) {
        f = q1[i];
        while (used[f] && f > 0) {
          cout << f << " ";
          used1[f] = 1;
          --f;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
