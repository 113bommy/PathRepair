#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, char> a[10];
  string s;
  cin >> s;
  a[1].first = s.size() - 2;
  a[1].second = s[0];
  cin >> s;
  a[2].first = s.size() - 2;
  a[2].second = s[0];
  cin >> s;
  a[3].first = s.size() - 2;
  a[3].second = s[0];
  cin >> s;
  a[4].first = s.size() - 2;
  a[4].second = s[0];
  sort(a + 1, a + 5);
  if (a[1].first * 2 < a[2].first && a[4].first > a[3].first * 2) {
    cout << "C";
    return 0;
  }
  if (a[1].first * 2 <= a[2].first) {
    cout << a[1].second;
    return 0;
  } else {
    if (a[4].first >= a[3].first * 2) {
      cout << a[4].second;
      return 0;
    }
    cout << "C";
  }
}
