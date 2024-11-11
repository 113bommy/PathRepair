#include <bits/stdc++.h>
using namespace std;
int buy[100005], sell[100005];
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    char ch;
    int p, q;
    cin >> ch >> p >> q;
    if (ch == 'B') {
      buy[p] += q;
    } else
      sell[p] += q;
  }
  vector<pair<int, int> > ss;
  for (int i = 1, t = s; i <= 100000 and t; i++) {
    if (sell[i]) {
      ss.push_back(make_pair(i, sell[i]));
      t--;
    }
  }
  for (int i = ss.size() - 1; i >= 0; i--)
    cout << "S " << ss[i].first << ' ' << ss[i].second << '\n';
  for (int i = 100000, t = s; i >= 1 and t; i--) {
    if (buy[i]) {
      cout << "B " << i << ' ' << buy[i] << '\n';
      t--;
    }
  }
  return 0;
}
