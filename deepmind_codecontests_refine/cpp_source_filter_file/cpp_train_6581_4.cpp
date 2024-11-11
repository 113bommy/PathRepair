#include <bits/stdc++.h>
using namespace std;
int T, N;
string str;
map<pair<int, int>, int> F;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N >> str;
    F.clear();
    pair<int, int> pos = make_pair(0, 0);
    F[pos] = 0;
    int mnl = 1e9;
    pair<int, int> wh;
    for (int i = 1; i <= N; i++) {
      if (str[i - 1] == 'L') pos.first--;
      if (str[i - 1] == 'R') pos.first++;
      if (str[i - 1] == 'U') pos.second++;
      if (str[i - 1] == 'D') pos.second--;
      if ((F.find(pos) != F.end())) {
        int lf = F[pos];
        int l = i - lf;
        if (l < mnl) {
          mnl = l;
          wh = make_pair(lf + 1, i);
        }
      }
      F[pos] = i;
    }
    if (mnl == 1e9)
      cout << wh.first << ' ' << wh.second << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
