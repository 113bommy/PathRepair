#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n, m, t;
double k;
int main() {
  string s;
  int i, num;
  while (cin >> n >> m >> k) {
    mp.clear();
    for (i = 1; i <= n; i++) {
      cin >> s >> num;
      int tmp = (int)(k * num);
      if (tmp >= 100) mp[s] = tmp;
    }
    for (i = 1; i <= m; i++) {
      cin >> s;
      if (mp.count(s) == 0) mp[s] = 0;
    }
    map<string, int>::iterator it;
    cout << mp.size() << endl;
    for (it = mp.begin(); it != mp.end(); it++)
      cout << it->first << " " << it->second << endl;
  }
  return 0;
}
