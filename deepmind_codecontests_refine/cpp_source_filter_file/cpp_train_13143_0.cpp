#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &t : a) cin >> t;
    vector<int> ans;
    auto apply_rot = [&](int id) {
      rotate(a.begin() + id, a.begin() + id + 2, a.begin() + id + 3);
      ans.push_back(id);
    };
    for (int i = 0; i + 2 < n; i++) {
      int p = min_element(a.begin() + i, a.end()) - a.begin();
      int v = a[p];
      for (; p >= i + 2; p -= 2) {
        apply_rot(p - 2);
      }
      while (a[i] != v) apply_rot(i);
    }
    if (a[n - 2] > a[n - 1]) {
      for (int i = n - 1; i > 0; i--) {
        if (a[i] == a[i - 1]) {
          int v = a[i];
          for (int j = i; j + 2 < n; j += 2) {
            while (a[j + 2] != v) apply_rot(j);
          }
          int p = n - 1;
          if (a[n - 1] != v)
            apply_rot(n - 3);
          else {
            apply_rot(n - 3);
            apply_rot(n - 3);
            p = n - 2;
          }
          for (; p >= i + 2; p -= 2) {
            apply_rot(p - 2);
          }
          if (p != i) {
            apply_rot(p - 2);
          }
          break;
        }
      }
    }
    if (a[n - 3] == a[n - 1]) apply_rot(n - 3);
    if (!is_sorted(begin(a), end(a))) {
      cout << int(ans.size()) << endl;
      for (int t : ans) cout << t + 1 << " ";
      cout << endl;
    } else {
      puts("-1");
    }
  }
}
