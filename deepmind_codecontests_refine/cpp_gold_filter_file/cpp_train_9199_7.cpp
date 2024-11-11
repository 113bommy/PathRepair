#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > mm;
int a[2222], good[33], K;
bool ok(int h1, int h2) {
  vector<int> tmp = mm[h1];
  for (int i = 0; i < tmp.size(); i++)
    if (tmp[i] == h2) return false;
  mm[h1].push_back(h2);
  return true;
}
int main() {
  int ans = 0;
  string s, t;
  cin >> s >> t >> K;
  for (int i = 0; i < t.size(); i++) good[i] = t[i] - '0';
  for (int i = 0; i < s.size(); i++) a[i] = s[i] - 'a';
  for (int i = 0; i < s.size(); i++) {
    int cnt = 0, hash = 1, h2 = 1;
    for (int j = i; j < s.size(); j++) {
      hash = (hash * 4547 + a[j]) % 100007;
      h2 = (h2 * 172117 + a[j] + 7) % 100000007;
      if (good[a[j]] == 0 && ++cnt > K)
        break;
      else if (ok(hash, h2))
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
