#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > tab;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    tab.push_back(make_pair(a, i + 1));
  }
  sort(tab.begin(), tab.end());
  int r = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (tab[i].first == tab[i + 1].first) r++;
  }
  if (r < 2)
    cout << "NO\n";
  else {
    cout << "Yes\n";
    int t = 3, loc = 0;
    while (t--) {
      for (int i = 0; i < n - 1; ++i) {
        cout << tab[i].second << ' ';
      }
      cout << tab[n - 1].second << endl;
      for (int i = loc; i < n - 1; ++i) {
        if (tab[i].first == tab[i + 1].first) {
          swap(tab[i].second, tab[i + 1].second);
          loc = i + 1;
          break;
        }
      }
    }
  }
  return 0;
}
