#include <bits/stdc++.h>
using namespace std;
int a[202], ans[202], fre[102], mark[202];
map<int, int> m;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    fre[a[i]]++;
  }
  int cnt = 0, p = 0;
  for (int i = 10; i <= 99; i++) {
    if (fre[i] >= 2) {
      for (int j = 0; j < 2 * n; j++) {
        if (a[j] == i && !mark[j]) {
          ans[j] = 1;
          mark[j] = 1;
          break;
        }
      }
      for (int j = 0; j < 2 * n; j++)
        if (a[j] == i && !mark[j]) {
          ans[j] = 2;
          mark[j] = 1;
          break;
        }
    } else if (fre[i]) {
      fre[i] = 0;
      for (int j = 0; j < 2 * n; j++)
        if (a[j] == i) p = j;
      if (cnt)
        ans[p] = 1;
      else
        ans[p] = 2;
      cnt ^= 1;
      mark[p] = 1;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (!mark[i]) {
      if (cnt)
        ans[i] = 1;
      else
        ans[i] = 2;
      cnt ^= 1;
    }
  }
  set<pair<int, int> > st;
  vector<int> v1, v2;
  for (int i = 0; i < 2 * n; i++) {
    if (ans[i] == 1)
      v1.push_back(a[i]);
    else
      v2.push_back(a[i]);
  }
  for (auto i : v1)
    for (auto j : v2) st.insert(make_pair(i, j));
  cout << st.size() << endl;
  for (int i = 0; i < 2 * n; i++) cout << ans[i] << " ";
  return 0;
}
