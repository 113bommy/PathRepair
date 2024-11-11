#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int m, h;
    char c;
    cin >> h >> c >> m;
    int time = h * 60 + m;
    v.push_back(time);
  }
  sort(v.begin(), v.end());
  int ans = -100;
  for (int i = 1; i < n; i++) ans = max(v[i] - v[i - 1] - 1, ans);
  ans = max(v[0] + 1440 - v[n - 1] - 1, ans);
  if (n == 1) {
    cout << "23:59";
  } else {
    int h = ans / 60;
    int m = ans - 60 * h;
    if (h < 10) cout << 0;
    cout << h;
    cout << ":";
    if (m < 10) cout << 0;
    cout << m;
  }
  return 0;
}
