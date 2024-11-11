#include <bits/stdc++.h>
using namespace std;
int go(int a, int b, int r) {
  cout << "? " << a + 1 << " " << b + 1 << " " << r + 1 << endl;
  int c;
  cin >> c;
  --c;
  return c;
}
long long h, n, a, b, c, r;
map<int, int> ma;
int cnt(int r) {
  int a, b;
  int num = 0;
  for (int ex = 0; ex < 27; ++ex) {
    a = b = 0;
    while (!(a != b && a != r && b != r)) {
      a = (rand() * 1ll * rand()) % n;
      b = (rand() * 1ll * rand()) % n;
    }
    if (go(a, b, r) == r) ++num;
  }
  return num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> h;
  n = (1 << h) - 1;
  if (h < 5) {
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
      v.push_back({cnt(i), i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int a = v[0].second;
    int b = v[1].second;
    int c = v[2].second;
    if (go(a, b, c) == c)
      cout << "! " << c + 1 << endl;
    else if (go(a, c, b) == b)
      cout << "! " << b + 1 << endl;
    else
      cout << "! " << a + 1 << endl;
    return 0;
  }
  for (int ex = 0; ex < 300; ++ex) {
    a = b = r = 0;
    while (!(a != b && b != r && a != r)) {
      a = (rand() * 1ll * rand()) % n;
      b = (rand() * 1ll * rand()) % n;
      r = (rand() * 1ll * rand()) % n;
    }
    ++ma[go(a, b, r)];
  }
  vector<pair<int, int> > v;
  for (auto el : ma) v.push_back({el.second, el.first});
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int a = v[0].second;
  int b = v[1].second;
  for (int i = 0; i < n; ++i) {
    if (i == a || i == b) continue;
    if (go(a, b, i) == i) {
      cout << "! " << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
