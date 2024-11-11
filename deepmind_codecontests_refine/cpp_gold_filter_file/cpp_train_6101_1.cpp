#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
string s[MAX];
int n;
vector<pair<int, int> > v;
vector<pair<int, int> > st;
char ss[1000010];
vector<int> vv[10000000];
int main() {
  int len = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", ss);
    s[i] = ss;
    int k, x;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &x);
      x--;
      len = max(len, x + (int)s[i].size());
      vv[x].push_back(i);
    }
  }
  string res(len, 'a');
  for (int i = 0; i < res.size(); i++) {
    if (i < 10000000)
      for (int j = 0; j < vv[i].size(); j++)
        st.push_back(make_pair(i, vv[i][j]));
    while (st.size() > 0 && i - st.back().first >= s[st.back().second].size())
      st.pop_back();
    if (st.size() > 0) res[i] = s[st.back().second][i - st.back().first];
  }
  cout << res;
  return 0;
}
