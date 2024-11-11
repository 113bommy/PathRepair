#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAXN = 1100;
int mp[MAXN][MAXN];
vector<int> va[2];
bool ask(int i, int j) {
  if (mp[i][j]) return mp[i][j] == -1;
  if (mp[j][i]) return mp[j][i] == 1;
  cout << "? " << i << " " << j << endl;
  char out;
  cin >> out;
  if (out == '<')
    mp[i][j] = -1;
  else
    mp[i][j] = 1;
  mp[j][i] = -mp[i][j];
  return mp[i][j] == -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int kase;
  cin >> kase;
  while (kase--) {
    memset(mp, 0, sizeof(mp));
    va[0].clear();
    va[1].clear();
    int nlen;
    cin >> nlen;
    int idx = 5;
    for (int i = 0; i < (nlen + 1) / 2; i++) {
      va[0].push_back(i + 1);
    }
    for (int i = (nlen + 1) / 2; i < (nlen + 1); i++) {
      va[1].push_back(i + 1);
    }
    for (int i = nlen + 2; i <= 2 * nlen; i++) {
      sort(va[0].begin(), va[0].end(), [](int a, int b) { return ask(a, b); });
      sort(va[1].begin(), va[1].end(), [](int a, int b) { return ask(a, b); });
      if (ask(va[0][0], va[1][0])) {
        va[0].erase(va[0].begin());
      } else
        va[1].erase(va[1].begin());
      if (va[0].size() < 2)
        va[0].push_back(i);
      else
        va[1].push_back(i);
    }
    sort(va[0].begin(), va[0].end(), [](int a, int b) { return ask(a, b); });
    sort(va[1].begin(), va[1].end(), [](int a, int b) { return ask(a, b); });
    ask(va[0][0], va[1][0]);
    cout << "!" << endl;
  }
  return 0;
}
