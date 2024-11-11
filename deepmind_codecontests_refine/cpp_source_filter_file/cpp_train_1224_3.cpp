#include <bits/stdc++.h>
using namespace std;
int n, m;
int possa[15], possb[15];
int can_deduce(vector<pair<int, int> > a, vector<pair<int, int> > b, int t) {
  for (int i = 0; i < n; i++) {
    pair<int, int> p1 = a[i];
    int flag = 0;
    int common = p1.first;
    for (int j = 0; j < m; j++) {
      pair<int, int> p2 = b[j];
      if (p1 == p2) continue;
      if (p2.first == common || p2.second == common) flag |= 1;
    }
    common = p1.second;
    for (int j = 0; j < m; j++) {
      pair<int, int> p2 = b[j];
      if (p1 == p2) continue;
      if (p2.first == common || p2.second == common) flag |= 2;
    }
    if (flag == 3) {
      return 0;
    } else if (flag == 1) {
      if (t == 1)
        possa[i] = p1.first;
      else
        possb[i] = p1.first;
    } else if (flag == 2) {
      if (t == 1)
        possa[i] = p1.second;
      else
        possb[i] = p1.second;
    } else {
      if (t == 1)
        possa[i] = -1;
      else
        possb[i] = -1;
    }
  }
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<pair<int, int> > a;
  vector<pair<int, int> > b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    a.push_back({x, y});
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    b.push_back({x, y});
  }
  int flag = can_deduce(a, b, 1);
  if (flag == 0) {
    cout << "-1\n";
    return 0;
  }
  swap(n, m);
  flag = can_deduce(b, a, 2);
  if (flag == 0) {
    cout << "-1\n";
    return 0;
  }
  int c1 = -1;
  swap(n, m);
  for (int i = 0; i < n; i++) {
    if (possa[i] == -1) continue;
    if (c1 == -1) c1 = possa[i];
    if (c1 != possa[i]) {
      cout << "0\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (possb[i] == -1) continue;
    if (c1 != possb[i]) {
      cout << "0\n";
      return 0;
    }
  }
  cout << 1 << "\n";
  return 0;
}
