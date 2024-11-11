#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m;
  string b[n];
  pair<string, string> a[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i].first;
    cin >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    for (int j = 0; j < n; j++) {
      if (b[i] == a[j].first || b[i] == a[j].second) {
        x = a[j].first.length();
        y = a[j].second.length();
        if (x <= y)
          cout << a[j].first << " ";
        else
          cout << a[j].second << " ";
        break;
      }
    }
  }
}
