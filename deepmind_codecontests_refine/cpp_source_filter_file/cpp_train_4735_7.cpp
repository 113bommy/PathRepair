#include <bits/stdc++.h>
using namespace std;
vector<int> ind[30];
int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < t.size(); i++) ind[t[i] - 'a'].push_back(i);
  int pos = 0;
  int current = 0;
  while (pos < s.size()) {
    int cur = s[pos] - 'a';
    int tw = upper_bound(ind[cur].begin(), ind[cur].end(), current) -
             ind[cur].begin();
    if (tw == ind[cur].size()) {
      cout << 0 << endl;
      return 0;
    }
    current = ind[cur][tw];
    pos++;
  }
  if (pos != s.size()) {
    cout << 0 << endl;
    return 0;
  }
  int Left = current;
  reverse(t.begin(), t.end());
  reverse(s.begin(), s.end());
  for (int i = 0; i < 30; i++) ind[i].clear();
  for (int i = 0; i < t.size(); i++) ind[t[i] - 'a'].push_back(i);
  pos = 0;
  current = 0;
  while (pos < s.size()) {
    int cur = s[pos] - 'a';
    int tw = upper_bound(ind[cur].begin(), ind[cur].end(), current) -
             ind[cur].begin();
    if (tw == ind[cur].size()) {
      cout << 0 << endl;
      return 0;
    }
    current = ind[cur][tw];
    pos++;
  }
  if (pos != s.size()) {
    cout << 0 << endl;
    return 0;
  }
  int right = t.size() - current - 1;
  Left++;
  cout << max(0, right - Left + 1) << endl;
  return 0;
}
