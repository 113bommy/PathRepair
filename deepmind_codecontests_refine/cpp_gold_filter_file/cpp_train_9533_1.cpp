#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 1000005;
int n, e, h;
string s, tmp;
pair<int, int> sa[N];
int ans[N];
vector<string> res[N];
string b[N];
int main() {
  int i, j, sum, id, maxi;
  while (cin >> s) {
    n = (s).size(), e = h = maxi = 0;
    for (i = 0; i < n; i++) {
      tmp.clear();
      while ((s[i] >= 'a' && s[i] <= 'z') || ((s[i] >= 'A' && s[i] <= 'Z')))
        tmp += s[i++];
      b[++e] = tmp;
      id = e;
      sum = 0, i++;
      while (s[i] >= '0' && s[i] <= '9') sum = sum * 10 + (s[i++] - '0');
      sa[++h] = make_pair(sum, 1);
      ans[id] = h;
      maxi = max(maxi, h);
      if (sa[h].first == 0) {
        h--;
        while (h > 0 && (sa[h].first == sa[h].second)) h--;
        sa[h].second++;
      }
    }
    for (int i = (1); i <= (maxi); i++) res[i].clear();
    for (int i = (1); i <= (e); i++) res[ans[i]].push_back(b[i]);
    cout << maxi << '\n';
    for (int i = (1); i <= (maxi); i++) {
      for (__typeof__((res[i]).begin()) it = (res[i]).begin();
           it != (res[i]).end(); it++)
        cout << *it << ' ';
      puts("");
    }
  }
  return 0;
}
