#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<string, string> in[n];
  pair<string, string> a[m];
  string f, s;
  for (int i = 0; i < n; i++) {
    cin >> f;
    cin >> s;
    s = s + ";";
    in[i].first = f;
    in[i].second = s;
  }
  for (int i = 0; i < m; i++) {
    cin >> f;
    cin >> s;
    a[i].first = f;
    a[i].second = s;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i].second == in[j].second) {
        cout << a[i].first << " " << a[i].second << " #" << in[j].first << endl;
        break;
      }
    }
  }
  return 0;
}
