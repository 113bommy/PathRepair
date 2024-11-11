#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> x;
void change2(int n, vector<int> &a, vector<int> k) {
  deque<int> y, z;
  for (int i = 0; i < n; i++) {
    y.push_back(a[i]);
  }
  for (int i : k) {
    deque<int> t;
    for (int j = 0; j < i; j++) {
      t.push_back(y.front());
      y.pop_front();
    }
    while (t.size()) {
      z.push_front(t.back());
      t.pop_back();
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = z[i];
  }
}
void change(int i, int j, int n, vector<int> &a) {
  int e = i + 1;
  while (e < n && a[e] - a[e - 1] == 1) {
    e++;
  }
  e--;
  vector<int> k;
  if (i > 0) {
    k.push_back(i - 1);
  }
  k.push_back(e - i + 1);
  k.push_back(j - e);
  if (j + 1 < n) {
    k.push_back(n - 1 - j);
  }
  x.push_back(k);
  change2(n, a, k);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (true) {
    bool f = false;
    for (int i = 0; i < n && !f; i++) {
      for (int j = i + 1; j < n && !f; j++) {
        if (a[i] - a[j] == 1) {
          f = true;
          change(i, j, n, a);
        }
      }
    }
    if (!f) {
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  cout << (int)(x.size()) << endl;
  for (int i = 0; i < x.size(); i++) {
    cout << (int)(x[i].size()) << ' ';
    for (int j : x[i]) {
      cout << j << ' ';
    }
    cout << endl;
  }
  return 0;
}
