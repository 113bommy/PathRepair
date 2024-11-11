#include <bits/stdc++.h>
using namespace std;
int N, T, p[400100];
vector<int> v;
int main() {
  cin.sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    v.clear();
    int g = 0, s = 0, b = 0, cnt = 0;
    for (int i = 1; i <= N; ++i) {
      cin >> p[i];
      if (p[i] != p[i - 1]) {
        if (cnt) v.push_back(cnt);
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    if (cnt) v.push_back(cnt);
    for (auto x : v) {
      if (g == 0) {
        g = x;
      } else if (s <= g) {
        s += x;
      } else if (s + g + b + x <= N / 2) {
        b += x;
      } else {
        break;
      }
    }
    if (s + b + g > N / 2 || b <= g) {
      g = s = b = 0;
    }
    cout << g << " " << s << " " << b << "\n";
  }
  return 0;
}
