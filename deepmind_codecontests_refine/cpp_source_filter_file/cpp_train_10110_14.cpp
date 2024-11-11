#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n, m, K;
double k;
map<string, int> hm;
map<string, bool> hb;
set<pair<string, int> > res;
int main() {
  string str;
  int lv;
  cin >> n >> m >> k;
  K = (k * 100.0);
  for (int i = 1; i <= n; i++) {
    cin >> str >> lv;
    int nlv = lv * K / 100;
    if (nlv >= 100) {
      hm[str] = nlv;
      hb[str] = true;
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> str;
    if (!hb[str]) hm[str] = 0;
  }
  for (map<string, int>::iterator it = hm.begin(); it != hm.end(); it++)
    res.insert(make_pair((*it).first, (*it).second));
  cout << res.size() << endl;
  for (set<pair<string, int> >::iterator it = res.begin(); it != res.end();
       it++)
    cout << (*it).first << " " << (*it).second << endl;
  return 0;
}
