#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<long long, int> > t;
  for (int i = 0; i < n; i++) {
    t.push_back(make_pair(a[i], i));
  }
  sort(t.begin(), t.end(), greater<pair<long long, int> >());
  vector<long long> b;
  int vbf = 0;
  for (int i = 0; i < n; i++) {
    if (t[i].second >= vbf) {
      b.push_back(t[i].second + 1);
      vbf = t[i].second;
    }
  }
  int g = 0;
  for (int i = 0; i < n; i++) {
    if (b[g] == i + 1) g++;
    if (g < b.size()) {
      if (a[b[g] - 1] - a[i] > 0)
        cout << a[b[g] - 1] - a[i] + 1 << ' ';
      else
        cout << 0 << ' ';
    } else
      cout << 0;
  }
}
