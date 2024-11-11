#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> pl;
string ans;
int k;
int main() {
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; i++) pl.push_back(i);
  while (k > 0) {
    int pos = 0;
    long long cnt[30] = {0};
    for (int i = 0; i < pl.size(); i++) {
      if (pl[i] + ans.size() < n)
        cnt[s[pl[i] + ans.size()] - 'a'] += (n - pl[i] - ans.size());
    }
    while (pos < 26 && k - cnt[pos] > 0) {
      k -= cnt[pos];
      pos++;
    }
    if (pos >= 26) {
      cout << "No such line." << endl;
      return 0;
    }
    vector<int> tmp;
    for (int i = 0; i < pl.size(); i++)
      if (pl[i] + ans.size() < n && s[pl[i] + ans.size()] == pos + 'a') {
        tmp.push_back(pl[i]);
      }
    swap(tmp, pl);
    k -= pl.size();
    ans += 'a' + pos;
  }
  cout << ans << endl;
  return 0;
}
