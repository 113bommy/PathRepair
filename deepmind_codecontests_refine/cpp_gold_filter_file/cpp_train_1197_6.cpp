#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<pair<int, int> > v[400005];
vector<int> Index[400005];
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[200005 + y - x].push_back(make_pair(x, y));
    s.insert(200005 + y - x);
  }
  int w[n];
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    Index[w[i] + 200005].push_back(i);
  }
  bool ans = true;
  vector<pair<int, int> > sol;
  sol.resize(n + 1);
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (Index[*it].size() == 0) {
      ans = false;
      break;
    }
    sort(v[*it].begin(), v[*it].end());
    for (int i = 0; i < v[*it].size(); i++) sol[Index[*it][i]] = v[*it][i];
  }
  if (ans) {
    set<pair<int, int> > check;
    for (int i = 0; i < n; i++) {
      check.insert(sol[i]);
      auto itr = check.upper_bound(make_pair(sol[i].first, sol[i].second));
      if (itr != check.end() && itr->first >= sol[i].first &&
          itr->second >= sol[i].second) {
        ans = false;
        break;
      }
    }
  }
  if (!ans)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << sol[i].first << " " << sol[i].second << endl;
  }
  return 0;
}
