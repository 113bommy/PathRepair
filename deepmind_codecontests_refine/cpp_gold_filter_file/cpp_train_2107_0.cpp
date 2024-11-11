#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n, 0);
  bool flag = false;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      flag = true;
    }
  }
  if (!flag) {
    cout << "1\n";
    for (int i = 0; i < n; i++) {
      cout << "1 ";
    }
    cout << '\n';
    return;
  }
  if (n % 2 == 0) {
    cout << "2\n";
    for (int i = 0; i < n; i++) {
      cout << i % 2 + 1 << ' ';
    }
    cout << '\n';
  } else {
    if (a[0] == a[n - 1]) {
      cout << "2\n";
      ans[0] = 1;
      ans[n - 1] = 1;
      for (int i = 1; i < n - 1; i++) {
        ans[i] = i % 2 + 1;
      }
      for (auto i : ans) cout << i << ' ';
      cout << '\n';
      return;
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        cout << "2\n";
        if (i % 2) {
          for (int j = 0; j < i; j++) {
            if (j % 2) {
              cout << "1 ";
            } else {
              cout << "2 ";
            }
          }
          cout << "1 1 ";
          for (int j = i + 2; j < n; j++) {
            cout << j % 2 + 1 << ' ';
          }
        } else {
          for (int j = 0; j < i; j++) {
            cout << j % 2 + 1 << ' ';
          }
          cout << "1 1 ";
          for (int j = i + 2; j < n; j++) {
            if (j % 2) {
              cout << "1 ";
            } else {
              cout << "2 ";
            }
          }
        }
        cout << '\n';
        return;
      }
    }
    cout << "3\n";
    for (int i = 0; i < n - 1; i++) {
      cout << i % 2 + 1 << ' ';
    }
    cout << 3 << '\n';
  }
}
int main() {
  string file("series");
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
}
