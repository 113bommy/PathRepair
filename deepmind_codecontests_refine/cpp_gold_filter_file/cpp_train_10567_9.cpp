#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r, k, p;
    vector<char> v;
    cin >> l >> r >> k;
    if (r == l) {
      continue;
    }
    l--;
    r--;
    p = r - l + 1;
    k = k % p;
    for (int j = r - k + 1; j <= r; j++) {
      v.push_back(s[j]);
    }
    for (int j = l; j < r - k + 1; j++) {
      v.push_back(s[j]);
    }
    int pq = 0;
    for (int j = l; j <= r; j++) {
      s[j] = v[pq];
      pq++;
    }
  }
  cout << s << endl;
}
