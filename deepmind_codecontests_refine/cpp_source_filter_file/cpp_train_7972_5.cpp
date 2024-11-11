#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<pair<int, int>> ap(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    ap[i] = make_pair(x, i);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[i] = x;
  }
  sort(ap.begin(), ap.end());
  cout << to_string(n / 2 + 1) << endl;
  cout << to_string(ap.back().second + 1) + " ";
  for (int i = n - 2; i > 0;) {
    if (i == 0) {
      cout << to_string(ap[i].second + 1) + " ";
      break;
    }
    int k = ap[i].second, t = ap[i - 1].second;
    if (b[k] >= b[t])
      cout << to_string(k + 1) + " ";
    else
      cout << to_string(t + 1) + " ";
    i -= 2;
  }
  return 0;
}
