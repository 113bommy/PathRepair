#include <bits/stdc++.h>
using namespace std;
int L, b, fr;
int n, m;
pair<int, int> st[128];
int loc[128];
int main() {
  cin >> L >> b >> fr;
  cin >> n;
  m = 0;
  st[0].first = -b;
  st[0].second = -b;
  for (int i = 1; i <= n; i++) {
    int tip;
    cin >> tip;
    st[m + 1].first = L + fr;
    if (tip == 1) {
      int lung;
      cin >> lung;
      loc[i] = -1;
      for (int j = 0; j <= m; j++)
        if (st[j].second + b + lung + fr <= st[j + 1].first) {
          cout << st[j].second + b << "\n";
          loc[i] = st[j].second + b;
          st[++m] = make_pair(st[j].second + b, st[j].second + b + lung);
          break;
        }
      if (loc[i] == -1) cout << "-1\n";
    } else {
      int index, ok = 0;
      cin >> index;
      for (int j = 0; j <= m; j++)
        if (st[j].first == loc[index]) {
          swap(st[j], st[m--]);
          break;
        }
    }
    sort(st, st + m);
  }
  return 0;
}
