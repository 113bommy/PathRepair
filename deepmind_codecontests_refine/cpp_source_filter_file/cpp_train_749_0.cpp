#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7, mod = 1e9 + 7;
const long long INF = 1e18 + 9;
void run() {
  string s;
  cin >> s;
  vector<vector<int> > Ans;
  vector<char> U((int)s.size());
  int r;
  vector<int> Vop, Vcl, V;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == '(')
      Vop.push_back(i);
    else
      Vcl.push_back(i);
  reverse(Vcl.begin(), Vcl.end());
  vector<pair<int, int> > A((int)s.size() + 1, make_pair(0, 0));
  for (;;) {
    r = 0;
    A[0].first = A[(int)s.size()].second = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      A[i + 1].first = A[i].first;
      if (U[i]) continue;
      A[i + 1].first += (s[i] == '(');
    }
    for (int i = (int)s.size() - 1; i > -1; --i) {
      A[i].second = A[i + 1].second;
      if (U[i]) continue;
      A[i].second += (s[i] == ')');
      if (min(A[i].second, A[i + 1].first) < r) break;
      r = min(A[i].second, A[i + 1].first);
    }
    if (!r) break;
    Ans.resize((int)Ans.size() + 1);
    Ans.back().push_back(r);
    int k = 0;
    for (auto it : Vop) {
      if (U[it]) continue;
      U[it] = true;
      ++k;
      Ans.back().push_back(it + 1);
      if (k == r) break;
    }
    k = 0;
    V.clear();
    for (auto it : Vcl) {
      if (U[it]) continue;
      U[it] = true;
      ++k;
      V.push_back(it + 1);
      if (k == r) break;
    }
    for (int j = (int)V.size() - 1; j > -1; --j) Ans.back().push_back(V[j]);
  }
  cout << (int)Ans.size() << '\n';
  for (auto i : Ans) {
    cout << i[0] << '\n';
    for (int j = 1; j < (int)i.size(); ++j) cout << i[j] << ' ';
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    run();
    cout << '\n';
  }
  return 0;
}
