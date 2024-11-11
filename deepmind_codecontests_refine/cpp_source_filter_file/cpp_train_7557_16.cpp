#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<char, int> m;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) m[a[i]] = 1;
  int num;
  cin >> num;
  string q;
  while (num--) {
    cin >> q;
    if (q.size() < b.size() - 1) {
      cout << "NO" << endl;
      continue;
    }
    bool flag = true;
    int k;
    for (k = 0; b[k] && b[k] != '*' && flag; k++) {
      if (b[k] == '?') {
        if (!m[q[k]]) flag = false;
      } else if (b[k] != q[k])
        flag = 0;
    }
    if (!flag) {
      cout << "NO" << endl;
      continue;
    }
    if (!b[k] && flag) {
      if (!q[k]) {
        cout << "YES" << endl;
        continue;
      } else {
        cout << "NO" << endl;
        continue;
      }
    }
    int i, j;
    for (i = b.size() - 1, j = q.size() - 1; i > k && flag; i--, j--) {
      if (b[i] == '?') {
        if (!m[b[i]]) flag = 0;
      } else if (b[i] != q[j])
        flag = 0;
    }
    if (!flag) {
      cout << "NO" << endl;
      continue;
    }
    for (i = k; i <= j && flag; i++) {
      if (m[q[i]]) flag = 0;
    }
    if (!flag) {
      cout << "NO" << endl;
      continue;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
