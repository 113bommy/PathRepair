#include <bits/stdc++.h>
using namespace std;
vector<int> fun(vector<int>& v) {
  set<int> s, s1;
  unordered_map<int, int> m;
  for (int i = 0; i < v.size(); i++) {
    m[v[i]]++;
    if (i != v[i]) s1.insert(i);
  }
  for (int i = 0; i <= v.size(); i++) {
    if (m[i] == 0) s.insert(i);
  }
  vector<int> ans;
  while (s1.size() > 0) {
    int a = *s.begin();
    s.erase(a);
    if (a != v.size()) {
      int b = v[a];
      v[a] = a;
      m[b]--;
      m[a]++;
      if (m[b] == 0) s.insert(b);
      ans.push_back(a);
      s1.erase(a);
      m[a]++;
    } else {
      int k = *s1.begin();
      int b = v[k];
      m[b]--;
      m[a]++;
      v[k] = a;
      ans.push_back(a);
      if (m[b] == 0) s.insert(b);
    }
  }
  return ans;
}
int main() {
  int t, n;
  cin >> t;
  while (t > 0) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = fun(v);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
    cout << endl;
    t--;
  }
  return 0;
}
