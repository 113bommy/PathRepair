#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  set<int> days;
  set<int>::iterator it;
  bool v[51], h[51];
  memset(v, 0, 51);
  memset(h, 0, 51);
  cin >> n;
  for (int i = 1; i < n * n + 1; i++) {
    cin >> a >> b;
    if (!h[a] && !v[b]) {
      h[a] = 1;
      v[b] = 1;
      days.insert(i);
    }
  }
  for (it = days.begin(); it != days.end(); it++) cout << *it << " ";
  return 0;
}
