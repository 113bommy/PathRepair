#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t[n * 2], t1[n * 2];
  for (int i = 0; i < n * 2; i = i + 2) {
    cin >> t[i] >> t[i + 1];
    t1[i] = t[i];
    t1[i + 1] = t[i + 1];
  }
  for (int i = 0; i < n; i = i + 2) {
    if (t[i] != t[i + 1]) {
      cout << "rated";
      return 0;
    }
  }
  sort(t1, t1 + 2 * n, greater<int>());
  bool same = true;
  for (int i = 0; i < n * 2; i = i + 1) {
    if (t[i] != t1[i]) {
      same = false;
    }
  }
  if (same) {
    cout << "maybe";
  } else {
    cout << "unrated";
  }
  return 0;
}
