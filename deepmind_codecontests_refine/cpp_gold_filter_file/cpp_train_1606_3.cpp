#include <bits/stdc++.h>
using namespace std;
int n, b, a, i, g[200005], d[200005];
pair<int, int> p[200005];
string s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> p[i].first >> p[i + n].first;
    p[i].second = 1;
    p[i + n].second = 2;
  }
  sort(p, p + 2 * n);
  for (i = 0; i < n; i++) {
    if (p[i].second == 1) a++;
    if (p[i].second == 2) b++;
  }
  for (i = 0; i < a; i++) {
    d[i] = 1;
  }
  for (i = 0; i < b; i++) {
    g[i] = 1;
  }
  for (i = 0; i < n / 2; i++) {
    d[i] = 1;
  }
  for (i = 0; i < n / 2; i++) {
    g[i] = 1;
  }
  for (i = 0; i < n; i++) {
    cout << d[i];
  }
  cout << endl;
  for (i = 0; i < n; i++) {
    cout << g[i];
  }
}
