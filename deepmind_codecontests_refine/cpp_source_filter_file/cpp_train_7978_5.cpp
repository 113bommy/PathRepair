#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  pair<int, int> a[n + 1];
  int x = 0, y = 0;
  a[0].first = x;
  a[0].second = y;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      y++;
      a[i + 1].first = x;
      a[i + 1].second = y;
    } else if (s[i] == 'R') {
      x++;
      a[i + 1].first = x;
      a[i + 1].second = y;
    }
  }
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i].first == a[i].second) {
      if (a[i].second == a[i - 1].second && a[i + 1].first > a[i].first) {
        count++;
      } else if (a[i].first == a[i - 1].first &&
                 a[i + 1].second > a[i].second) {
        count++;
      }
    }
  }
  cout << count;
}
