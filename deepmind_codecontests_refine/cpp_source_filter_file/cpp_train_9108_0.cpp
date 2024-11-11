#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> p[n];
  int a, b, area;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p, p + n);
  if (n == 1)
    cout << "-1" << endl;
  else if (n == 2) {
    if (p[0].first != p[1].first && p[0].second != p[1].second) {
      area = abs(p[0].first - p[1].first) * abs(p[0].second - p[1].second);
      cout << area << endl;
    } else {
      cout << "-1" << endl;
    }
  } else if (n == 3) {
    if ((p[0].first == p[1].first && p[0].second == p[2].second)) {
      area = abs(p[0].second - p[1].second) * abs(p[0].first - p[2].first);
      cout << area << endl;
    } else if ((p[0].first == p[1].first && p[1].second == p[2].second)) {
      area = abs(p[0].first - p[2].first) * abs(p[0].second - p[2].second);
      cout << area << endl;
    } else if ((p[1].first == p[2].first && p[0].second == p[2].second)) {
      area = abs(p[0].first - p[1].first) * abs(p[1].second - p[2].second);
      cout << area << endl;
    } else if ((p[1].first == p[2].first && p[0].second == p[1].second)) {
      area = abs(p[0].first - p[2].first) * abs(p[0].second - p[2].second);
      cout << area << endl;
    } else
      cout << "-1" << endl;
  } else {
    if (p[0].first == p[1].first && p[2].first == p[3].first &&
        p[0].second == p[2].second && p[1].second == p[3].second) {
      area = abs(p[0].first - p[2].first) * abs(p[0].second - p[2].second);
      cout << area << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}
