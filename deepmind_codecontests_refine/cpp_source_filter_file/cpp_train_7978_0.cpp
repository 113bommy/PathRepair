#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T &x) {
  return x.size();
}
const int INF = ~(1 << 31);
const double pi = acos(-1);
const double EPS = 1e-9;
int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  pair<int, int> at(0, 0);
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = (0); i < (n - 1); i++) {
    pair<int, int> last = at;
    if (s[i] == 'U')
      at.first++;
    else
      at.second++;
    if (at.first == at.second) {
      if (last.first < last.second) {
        if (s[i + 1] == 'U') cnt++;
      } else {
        if (s[i + 1] == 'D') cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
