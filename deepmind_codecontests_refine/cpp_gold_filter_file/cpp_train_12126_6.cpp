#include <bits/stdc++.h>
using namespace std;
double tick() {
  static clock_t oldt, newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
int main() {
  int n;
  cin >> n;
  string st[101];
  int deg[26];
  vector<int> main[26];
  for (int i = 0; i < n; i++) cin >> st[i];
  bool flag = true;
  fill(deg, deg + 26, 0);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      int k = 0;
      string s1 = st[i], s2 = st[j];
      while (s1[k] == s2[k] && k < s1.size() && k < s2.size()) k++;
      if (k == s1.size()) continue;
      if (k == s2.size()) {
        flag = false;
        break;
      }
      main[s1[k] - 'a'].push_back(s2[k] - 'a');
      deg[s2[k] - 'a']++;
    }
    if (!flag) break;
  }
  if (flag) {
    set<int> s;
    vector<int> final;
    for (int i = 0; i < 26; i++) {
      if (deg[i] == 0) s.insert(i);
    }
    while (!s.empty()) {
      set<int>::iterator it = s.begin();
      int el = *it;
      s.erase(it);
      final.push_back(el);
      for (int i = 0; i < main[el].size(); i++) {
        deg[main[el][i]]--;
        if (deg[main[el][i]] == 0) s.insert(main[el][i]);
      }
    }
    if (final.size() != 26)
      cout << "Impossible\n";
    else {
      for (int i = 0; i < final.size(); i++) cout << (char)(final[i] + 'a');
      cout << "\n";
    }
  } else {
    cout << "Impossible\n";
  }
  cerr << "execution time is: " << tick() << "\n";
}
