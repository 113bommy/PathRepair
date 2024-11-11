#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = -1;
  cin >> n;
  pair<int, int> p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    if (p[i].second >= a) {
      a = p[i].second;
    } else {
      a = p[i].first;
    }
  }
  cout << a << '\n';
}
