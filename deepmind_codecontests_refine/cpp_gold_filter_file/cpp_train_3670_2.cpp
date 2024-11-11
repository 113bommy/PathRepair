#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> s;
void print(vector<int>& v) {
  int pos1, pos6;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 2) pos1 = i;
    if (v[i] == 5) pos6 = i;
    cout << v[i] << ' ';
  }
  cout << ' ' << pos1 << ' ' << pos6;
  cout << endl;
}
int dist(vector<int>& v, vector<int>& v1) {
  int diff = 0;
  map<int, int> pa, pb;
  for (int i = 0; i < v.size(); i++) {
    pa[v[i]] = i;
    pb[v1[i]] = i;
  }
  if (s.count(v) == 0) {
    int temp = 0;
  }
  for (int i = 0; i < v.size(); i++) {
    diff += pa[v[i]] - pa[v1[i]];
  }
  return diff;
}
void solve(vector<int> v) {
  if (s.count(v)) return;
  s[v];
  print(v);
  for (int i = 1; i <= v.size() / 2; i++) {
    vector<int> vs(v);
    if (i == 3) {
      int tem = 0;
    }
    for (int j = 0; j < i; j++) {
      swap(vs[j], vs[vs.size() + j - i]);
    }
    solve(vs);
  }
}
bool token[501];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> cnts;
    map<int, vector<int>> pb;
    memset(token, false, sizeof token);
    vector<int> a(n), b(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnts[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      cnts[b[i]]--;
      pb[b[i]].push_back(i);
      b[n + i] = b[i];
    }
    bool valid = true;
    for (int i = 0; i < n / 2; i++) {
      int x = a[i];
      int y = a[n - i - 1];
      vector<int>& v = pb[x];
      bool found = false;
      for (int j = 0; j < v.size(); j++) {
        int posx = v[j];
        int posy = n - 1 - posx;
        if (token[posx] || token[posy]) continue;
        if (b[posy] == y) {
          found = true;
          token[posx] = token[posy] = true;
          break;
        }
      }
      if (!found) {
        valid = false;
        break;
      }
    }
    if (n % 2 == 1) {
      valid &= (a[n / 2] == b[n / 2]);
    }
    if (valid) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
