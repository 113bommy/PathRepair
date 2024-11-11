#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int sm[200005];
int main() {
  string s;
  string vowels = "aeiouAEIOU";
  cin >> s;
  int i, j, l = s.length();
  for (i = 0; i < l; i++) {
    if (vowels.find(s[i]) != string::npos)
      sm[i + 1] = sm[i] - 1;
    else
      sm[i + 1] = sm[i] + 2;
    v.push_back(make_pair(sm[i + 1], i + 1));
  }
  v.push_back(make_pair(0, 0));
  sort(v.begin(), v.end());
  int ans = 0;
  int mn = v[0].second;
  for (i = 1; i <= l; i++) {
    ans = max(ans, v[i].second - mn);
    mn = min(mn, v[i].second);
  }
  if (ans == 0)
    cout << "No solution" << endl;
  else {
    int cnt = 0;
    for (i = 0; i + ans <= l; i++)
      if (sm[i + ans] - sm[i] >= 0) cnt++;
    cout << ans << " " << cnt << endl;
  }
  return 0;
}
