#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (v.size() == 0)
      v.push_back(make_pair(x, y));
    else {
      while (v.size() > 0) {
        int len = v.size();
        pair<int, int> temp = v[len - 1];
        if (temp.second <= y) {
          v.pop_back();
        } else
          break;
      }
      v.push_back(make_pair(x, y));
    }
  }
  vector<int> f;
  int t = v[0].second;
  for (int i = 0; i < t; i++) {
    f.push_back(a[i]);
  }
  v.push_back(make_pair(0, 0));
  sort(f.begin(), f.end());
  int L = 0, R = f.size() - 1;
  int len1 = v.size();
  int idx = len1 - 1;
  for (int i = 0; i < len1 - 1; i++) {
    int dis = v[i].second - v[i + 1].second;
    if (v[i].first == 1) {
      while (dis > 0) {
        a[idx] = f[R];
        idx--;
        R--;
        dis--;
      }
    } else {
      while (dis > 0) {
        a[idx] = f[L];
        idx--;
        L++;
        dis--;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}
