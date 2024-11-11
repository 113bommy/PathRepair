#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int TCase;
  cin >> TCase;
  while (TCase--) {
    unordered_map<int, int> counttable;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      counttable[a]++;
    }
    int ncolors = 0, appearcnt = 0;
    for (auto &[col, cnt] : counttable) {
      if (cnt > appearcnt)
        ncolors = 1, appearcnt = cnt;
      else if (cnt == appearcnt)
        ncolors++;
    }
    int allspace = n - ncolors * appearcnt;
    cout << allspace / (appearcnt - 1) << endl;
  }
  return 0;
}
