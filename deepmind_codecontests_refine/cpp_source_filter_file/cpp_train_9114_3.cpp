#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(0);
  int n, m;
  cin >> n >> m;
  map<int, queue<int> > p;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    p[t].push(i);
  }
  vector<int> s(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  int c = 0, u = 0;
  vector<int> used(m, 0);
  vector<int> a(m, 0), b(m, 0);
  bool flag = 1;
  for (int i = 0; flag; ++i) {
    long long sum = 0, cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (used[j]) {
        continue;
      }
      sum += s[j];
      ++cnt;
      if (p.count(s[j])) {
        ++c;
        u += i;
        int k = p[s[j]].front();
        p[s[j]].pop();
        if (p[s[j]].empty()) {
          p.erase(s[j]);
        }
        ++used[j];
        a[j] = i;
        b[k] = j + 1;
      }
      s[j] = (s[j] + 1) / 2;
    }
    flag = cnt < sum;
  }
  cout << c << " " << u << '\n';
  for (int i = 0; i < m; ++i) cout << a[i] << " ";
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << b[i] << " ";
  return 0;
}
