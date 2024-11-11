#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void prt(pair<int, pair<int, int> > x) {
  cout << x.first << "\n" << x.second.first << " " << x.second.second << "\n";
}
const int N = 300000;
int n;
string a;
int Bal[N + 1];
int Mn[N + 1], mN[N + 2];
int ori(int x, int y) { return x <= n - y + 1 ? x + y - 1 : x - (n - y + 1); }
int main() {
  cin >> n >> a;
  a = (string) " " + a;
  for (int i = 1; i <= n; i++) Bal[i] = Bal[i - 1] + (a[i] == '(' ? 1 : -1);
  Mn[0] = mN[N + 1] = inf;
  for (int i = 1; i <= n; i++) Mn[i] = min(Mn[i - 1], Bal[i]);
  for (int i = n; i; i--) mN[i] = min(mN[i + 1], Bal[i]);
  for (int i = 1; i <= n; i++)
    if (mN[i] - Bal[i - 1] >= 0 && Mn[i - 1] + Bal[n] - Bal[i - 1] >= 0 &&
        Bal[n] == 0) {
      a = (string) " " + a.substr(i, n - i + 1) + a.substr(1, i - 1);
      stack<int> stk;
      vector<pair<pair<int, int>, vector<pair<pair<int, int>, int> > > > v;
      for (int j = 1; j <= n;)
        if (a[j] == '(' && stk.empty()) {
          vector<pair<pair<int, int>, int> > vv;
          int cnt = 0;
          for (int k = j;; k++) {
            if (a[k] == '(')
              cnt += stk.size() == 2, stk.push(k);
            else
              stk.size() == 2
                  ? vv.push_back(make_pair(make_pair(stk.top(), k), cnt)),
                  cnt = 0 : 0, stk.pop();
            if (stk.empty()) {
              v.push_back(make_pair(make_pair(j, k), vv));
              j = k + 1;
              break;
            }
          }
        }
      pair<int, pair<int, int> > ans1 = make_pair(v.size(), make_pair(1, 1)),
                                 ans2 = make_pair(0, make_pair(0, 0)),
                                 ans3 = ans2;
      for (int j = 0; j < v.size(); j++) {
        ans2 = max(ans2, make_pair((int)v[j].second.size() + 1,
                                   make_pair(ori(v[j].first.first, i),
                                             ori(v[j].first.second, i))));
        int mx = 0;
        pair<int, int> mxid = make_pair(1, 1);
        for (int k = 0; k < v[j].second.size(); k++)
          if (v[j].second[k].second > mx)
            mx = v[j].second[k].second, mxid = v[j].second[k].first;
        if (v[j].second.size())
          ans3 = max(ans3, make_pair((int)v.size() + 1 + mx,
                                     make_pair(ori(mxid.first, i),
                                               ori(mxid.second, i))));
      }
      pair<int, pair<int, int> > ans = max(max(ans1, ans2), ans3);
      prt(ans);
      return 0;
    }
  puts("0\n1 1");
  return 0;
}
