#include <bits/stdc++.h>
using namespace std;
int a, s, d, d1[2], f, g, h, j, k, l, i, n, m, m1, m2;
priority_queue<pair<int, pair<int, int> > > q;
pair<int, int> p[300003];
int v[2];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m1 >> m2;
  for (i = 0; i < n; i++) {
    cin >> p[i].first;
    p[i].second = i + 1;
  }
  sort(p, p + n);
  reverse(p, p + n);
  for (i = 1; i <= n; i++) {
    if (p[i - 1].first >= (m1 + i - 1) / i) {
      for (a = 1; a <= n - i; a++) {
        if (p[i + a - 1].first >= (m2 + a - 1) / a) {
          cout << "Yes\n" << i << " " << a << endl;
          for (j = 0; j < i + a; j++) {
            if (j == i) cout << endl;
            cout << p[j].second << " ";
          }
          return 0;
        }
      }
      break;
    }
  }
  for (i = 1; i <= n; i++) {
    if (p[i - 1].first >= (m2 + i - 1) / i) {
      for (a = 1; a <= n - i; a++) {
        if (p[i + a - 1].first >= (m1 + a - 1) / a) {
          cout << "Yes\n" << a << " " << i << endl;
          for (j = i; j < i + a; j++) {
            cout << p[j].second << " ";
          }
          for (j = 0; j < i; j++) {
            cout << p[j].second << " ";
          }
          return 0;
        }
      }
      break;
    }
  }
  cout << "No";
}
