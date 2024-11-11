#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> p[n];
  int max_num = 0, min_num = 1000000;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p[i].first = a;
    p[i].second = b;
    if (a < min_num) min_num = a;
    if (b > max_num) max_num = b;
  }
  for (int j = 0; j < n; j++) {
    if (p[j].first == min_num && p[j].second == max_num) {
      cout << j + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
