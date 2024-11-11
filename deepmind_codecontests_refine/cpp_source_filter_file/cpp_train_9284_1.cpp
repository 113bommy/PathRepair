#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '.') {
        cnt++;
      } else {
        if (cnt >= b) {
          v.push_back(cnt);
        }
        cnt = 0;
      }
    }
    if (cnt >= b) {
      v.push_back(cnt);
    }
    if (v.empty()) {
      cout << "NO\n";
      continue;
    }
    sort(v.begin(), v.end());
    if (v[0] < a) {
      cout << "NO\n";
      continue;
    }
    if (v.size() == 1) {
      int len = v[0];
      if (len >= 4 * b + a - 1) {
        cout << "NO\n";
        continue;
      }
      if (len >= 3 * a || len <= 2 * b - 2 + a) {
        cout << "YES\n";
        continue;
      }
      cout << "NO\n";
      continue;
    }
    int prev = v[v.size() - 2];
    if (prev >= 2 * b) {
      cout << "NO\n";
      continue;
    }
    int last = v.back();
    if (last >= 4 * b + a - 1) {
      cout << "NO\n";
      continue;
    }
    if (last < a + b) {
      if (v.size() % 2 == 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
      continue;
    }
    int turns = v.size() - 1;
    if (turns % 2 == 0) {
      if (last <= a + 2 * b - 2 || last >= 3 * a) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (last < 2 * a) {
        cout << "NO\n";
        continue;
      }
      if (last <= 2 * a + 2 * b - 1) {
        cout << "YES\n";
        continue;
      }
      cout << "NO\n";
    }
  }
  return 0;
}
