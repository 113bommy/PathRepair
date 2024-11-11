#include <bits/stdc++.h>
using namespace std;
string s;
int k;
vector<int> active, tmp;
string ans;
int main() {
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; i++) active.push_back(i);
  while (k > 0) {
    long long cnt[30] = {0};
    for (int i = 0; i < active.size(); i++)
      if (ans.size() + active[i] < n)
        cnt[s[ans.size() + active[i]] - 'a'] += (n - ans.size() - active[i]);
    int pos = 0;
    while (k > cnt[pos] && pos < 26) {
      k -= cnt[pos];
      pos++;
    }
    if (pos >= 26) {
      cout << "No such line.";
      return 0;
    }
    tmp.clear();
    for (int i = 0; i < active.size(); i++)
      if (ans.size() + active[i] < n && s[ans.size() + active[i]] - 'a' == pos)
        tmp.push_back(i);
    ans.push_back(pos + 'a');
    k -= tmp.size();
    swap(active, tmp);
  }
  cout << ans << endl;
  return 0;
}
