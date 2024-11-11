#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int score[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
string name[maxn];
map<string, int> mp;
int t, n, cnt = 0;
vector<vector<int> > v1(maxn, vector<int>(60));
vector<vector<int> > v2(maxn, vector<int>(60));
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int mark;
      if (!mp.count(s)) {
        mp[s] = cnt;
        name[cnt] = s;
        mark = cnt;
        cnt++;
      } else
        mark = mp[s];
      if (i < 10) {
        v1[mark][0] += score[i];
        v2[mark][1] += score[i];
      }
      if (!i)
        v2[mark][0]++, v1[mark][1]++;
      else
        v1[mark][i + 1]++, v2[mark][i + 1]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < cnt; i++)
    if (v1[i] > v1[ans]) ans = i;
  cout << name[ans] << endl;
  for (int i = 0; i < cnt; i++)
    if (v2[i] > v2[ans]) ans = i;
  cout << name[ans] << endl;
  return 0;
}
