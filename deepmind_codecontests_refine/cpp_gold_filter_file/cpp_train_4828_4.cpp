#include <bits/stdc++.h>
using namespace std;
void task();
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  task();
  return 0;
}
vector<int> prefix_function(string s) {
  int n = s.length();
  vector<int> p(n, 0);
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) j = p[j - 1];
    if (s[i] == s[j]) p[i] = j + 1;
  }
  return p;
}
string s[3];
void task() {
  cin >> s[0] >> s[1] >> s[2];
  sort(s, s + 3);
  int ans = 1e9 + 10;
  do {
    string ss = s[0];
    {
      vector<int> p = prefix_function(s[1] + "!" + s[0]);
      int mx = 0;
      for (int i = s[1].length(); i < ((int)((p).size())); ++i)
        mx = max(mx, p[i]);
      if (p.back() != ((int)((s[1]).size())) && mx != ((int)((s[1]).size())))
        ss += s[1].substr(p.back(), ((int)((s[1]).size())) - p.back());
    }
    {
      vector<int> p = prefix_function(s[2] + "!" + ss);
      int mx = 0;
      for (int i = s[2].length(); i < ((int)((p).size())); ++i)
        mx = max(mx, p[i]);
      if (p.back() != ((int)((s[2]).size())) && mx != ((int)((s[2]).size())))
        ss += s[2].substr(p.back(), ((int)((s[2]).size())) - p.back());
      ans = min(ans, ((int)((ss).size())));
    }
  } while (next_permutation(s, s + 3));
  cout << ans;
}
