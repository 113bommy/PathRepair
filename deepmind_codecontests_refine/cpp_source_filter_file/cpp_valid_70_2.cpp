#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 99;
bool chk(map<char, int> m1, map<char, int> m2, string s) {
  bool result = true;
  for (int i = 0; i < s.size(); i++) {
    if (m1[s[i]] != m2[s[i]]) {
      result = false;
      break;
    }
  }
  return result;
}
bool re(string ans, string s, string t) {
  string tmp = ans;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      if (ans[j] == '!') continue;
      if (s[i] == ans[j]) {
        ans[j] = '!';
      } else {
        tmp += ans[j];
      }
    }
  }
  tmp = "#" + tmp;
  return tmp == t;
}
void slv() {
  string t, s = "", ans = "";
  map<char, int> idx, cnt, cnt1, tmp;
  cin >> t;
  t = "#" + t;
  for (int i = 1; i < t.size(); i++) {
    idx[t[i]] = i;
    cnt[t[i]]++;
  }
  vector<pair<int, char> > v;
  for (auto it : idx) {
    v.push_back({it.second, it.first});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    s += v[i].second;
    cnt1[v[i].second] = cnt[v[i].second] / (i + 1);
  }
  for (int i = 1; i < t.size(); i++) {
    tmp[t[i]]++;
    ans += t[i];
    if (chk(tmp, cnt1, s)) {
      break;
    }
  }
  if (!re(ans, s, t))
    puts("-1");
  else
    cout << ans << " " << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  long long cs = 1;
  while (t--) {
    slv();
  }
  return 0;
}
