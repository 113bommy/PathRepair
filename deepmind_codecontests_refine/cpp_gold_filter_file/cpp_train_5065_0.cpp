#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n;
int a[300][300];
vector<pair<pair<int, int>, int> > from[300];
int bild[300000];
int sum = 0;
vector<pair<pair<int, int>, pair<int, int> > > bd;
vector<pair<pair<int, int>, pair<int, int> > > ans;
void punch() {
  if (((int)(bd).size()) >= 7) return;
  if (((int)(bd).size()) >= ((int)(ans).size())) return;
  if (bild[n]) {
    if (((int)(bd).size()) < ((int)(ans).size())) {
      ans.clear();
      for (int i = 0; i < ((int)(bd).size()); i++) ans.push_back(bd[i]);
    }
    return;
  }
  for (int j = 0; j < ((int)(bd).size()); j++)
    for (int k = 1; k <= 8; k <<= 1) {
      int x = k * bd[j].first.first;
      if (!bild[x] && x <= n && x > bd.back().first.first) {
        bild[x] = 1;
        bd.push_back(make_pair(make_pair(x, k), make_pair(-1, j)));
        punch();
        bd.pop_back();
        bild[x] = 0;
      }
    }
  for (int i = 0; i < ((int)(bd).size()); i++)
    for (int j = 0; j < ((int)(bd).size()); j++)
      for (int k = 1; k <= 8; k <<= 1) {
        int x = bd[i].first.first + k * bd[j].first.first;
        if (!bild[x] && x <= n && x > bd.back().first.first) {
          bild[x] = 1;
          bd.push_back(make_pair(make_pair(x, k), make_pair(i, j)));
          punch();
          bd.pop_back();
          bild[x] = 0;
        }
      }
}
string reg(int x) {
  string s = "a";
  s[0] = 'a' + x;
  return "e" + s + "x";
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) bild[i] = 0;
  bild[1] = 1;
  bd.push_back(make_pair(make_pair(1, 1), make_pair(1, 1)));
  for (int i = 0; i < 1000; i++)
    ans.push_back(make_pair(make_pair(1, 1), make_pair(1, 1)));
  punch();
  cout << ((int)(ans).size()) - 1 << endl;
  for (int i = 1; i < ((int)(ans).size()); i++) {
    cout << "lea " << reg(i) << ", [";
    if (ans[i].second.first >= 0) cout << reg(ans[i].second.first) << " + ";
    cout << ans[i].first.second << "*" << reg(ans[i].second.second) << "]"
         << endl;
  }
}
