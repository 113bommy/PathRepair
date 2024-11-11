#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
vector<int> vtc[MAXN];
set<int> ctv[MAXN];
int curSize[MAXN];
int val[MAXN];
bool isOk[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  int c, v;
  cin >> c >> v;
  for (int i = 0; i < (c); ++i) {
    int num, vCur;
    cin >> num;
    while (num--) {
      cin >> vCur;
      ctv[i].insert(vCur);
      vtc[abs(vCur)].push_back(i);
    }
  }
  for (int i = 0; i < (c); ++i) curSize[i] = (int)(ctv[i]).size();
  priority_queue<pair<int, int> > q;
  for (int i = 0; i < (c); ++i) q.push(make_pair(-curSize[i], i));
  while (!q.empty()) {
    int cl = q.top().second;
    q.pop();
    if (isOk[cl]) continue;
    if ((int)(ctv[cl]).size() == 0) {
      cout << "NO\n";
      return 0;
    }
    int va = *ctv[cl].begin();
    int vabs = abs(va);
    ctv[cl].erase(va);
    isOk[cl] = true;
    val[vabs] = (va > 0 ? 1 : 0);
    for (int x : vtc[vabs]) {
      if (ctv[x].count(va)) {
        isOk[x] = true;
        ctv[x].erase(va);
      } else {
        ctv[x].erase(-va);
        q.push(make_pair(-(int)(ctv[x]).size(), x));
      }
    }
  }
  cout << "YES\n";
  for (int i = (1); i <= (v); ++i) cout << val[i];
  cout << endl;
  return 0;
}
