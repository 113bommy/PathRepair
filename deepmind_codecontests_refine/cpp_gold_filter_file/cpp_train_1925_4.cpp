#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 10, mod = 10007;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int& i : a) cin >> i;
  int b[n];
  for (int& i : b) cin >> i;
  vector<pair<int, int> > u;
  for (int j = 0; j < n; j++)
    for (int i = 1; i < n; i++) {
      if (b[i] < b[i - 1]) {
        swap(b[i], b[i - 1]);
        u.push_back({i, i + 1});
      }
    }
  vector<pair<int, int> > y;
  for (int j = 0; j < n; j++)
    for (int i = 1; i < n; i++)
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        y.push_back({i, i + 1});
      }
  cout << y.size() + u.size() << endl;
  for (int i = 0; i < u.size(); i++) {
    cout << u[i].first << ' ' << u[i].second << endl;
  }
  for (int i = y.size() - 1; i >= 0; i--) {
    cout << y[i].first << ' ' << y[i].second << endl;
  }
}
