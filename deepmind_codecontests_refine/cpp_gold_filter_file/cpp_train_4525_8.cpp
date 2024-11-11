#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, pair<int, int> > > aa(n);
  vector<int> b(2005, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  aa.clear();
  bool p = false;
  int c = 0;
  for (int i = 0; i < 2005; i++) {
    if (b[i] >= 3) {
      p = true;
      break;
    }
    if (b[i] == 2) c++;
    if (c == 2) {
      p = true;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    aa.push_back(make_pair(a[i], make_pair(i, b[a[i]])));
  }
  sort(aa.begin(), aa.end());
  cout << (p ? "YES" : "NO") << endl;
  if (p) {
    for (int i = 0; i < n; i++) {
      cout << aa[i].second.first + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
      if (aa[i].first == aa[i + 1].first) swap(aa[i], aa[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      cout << aa[i].second.first + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
      if (aa[i].first == aa[i + 1].first) {
        swap(aa[i], aa[i + 1]);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << aa[i].second.first + 1 << " ";
    }
    cout << endl;
  }
}
