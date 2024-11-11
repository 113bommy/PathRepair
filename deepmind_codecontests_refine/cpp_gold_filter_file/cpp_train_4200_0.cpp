#include <bits/stdc++.h>
using namespace std;
const int SZ = 1E5 + 1000;
struct person {
  int sz;
  int num;
};
struct wear {
  int l, r;
  int num;
};
person a[SZ];
wear b[SZ];
int main() {
  int n, m;
  int x, y;
  vector<pair<int, int> > v;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i].sz;
    a[i].num = i + 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].l;
    b[i].r = b[i].l;
    b[i].l -= y;
    b[i].r += x;
    b[i].num = i + 1;
  }
  int j = 0;
  for (int i = 0; i < m; i++) {
    while (j < n && b[i].l > a[j].sz) {
      j++;
    }
    if (j < n && b[i].l <= a[j].sz && b[i].r >= a[j].sz) {
      v.push_back(make_pair(a[j].num, b[i].num));
      j++;
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
