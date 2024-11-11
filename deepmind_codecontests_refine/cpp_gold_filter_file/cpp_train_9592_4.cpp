#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
int b[maxn];
int n;
vector<pair<int, int>> v;
void borrow(int pos, int val) {
  if (val == 1) {
    if (a[pos + 1] == 0) borrow(pos + 1, -1);
    if (v.size() >= 100000) return;
    v.push_back(make_pair(pos, -1));
    a[pos + 1]--;
    a[pos]--;
  } else {
    if (a[pos + 1] == 9) borrow(pos + 1, 1);
    if (v.size() >= 100000) return;
    v.push_back(make_pair(pos, 1));
    a[pos + 1]++;
    a[pos]++;
  }
}
void solve() {
  for (int i = 1; i <= n - 1; i++) {
    while (a[i] != b[i]) {
      if (a[i] < b[i]) {
        if (a[i + 1] == 9) {
          borrow(i + 1, 1);
        }
        if (v.size() >= 100000) return;
        v.push_back(make_pair(i, 1));
        a[i]++;
        a[i + 1]++;
      } else {
        if (a[i + 1] == 0) {
          borrow(i + 1, -1);
        }
        if (v.size() >= 100000) return;
        v.push_back(make_pair(i, -1));
        a[i]--;
        a[i + 1]--;
      }
    }
  }
}
int main() {
  while (cin >> n) {
    v.clear();
    char c;
    for (int i = 1; i <= n; i++) {
      cin >> c;
      a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
      cin >> c;
      b[i] = c - '0';
    }
    long long ans = 0;
    int temp = a[1];
    for (int i = 1; i <= n - 1; i++) {
      ans += abs(b[i] - temp);
      temp = a[i + 1] + b[i] - temp;
    }
    if (temp != b[n]) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
    solve();
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << endl;
    }
  }
}
