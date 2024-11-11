#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
string f = "1";
bool sort2(string &a, string &b) {
  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();
}
void calc(string s) {
  if (s.size() >= 10) {
    return;
  }
  ans.push_back(s);
  s += '1';
  calc(s);
  s.pop_back();
  s += '0';
  calc(s);
  s.pop_back();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string l = to_string(n);
  calc(f);
  int ans2 = 0;
  sort(ans.begin(), ans.end(), sort2);
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i].size() > l.size()) {
      break;
    } else if (ans[i].size() == l.size()) {
      if (l >= ans[i]) {
        ans2++;
      } else {
        break;
      }
    } else {
      ans2++;
    }
  }
  cout << ans2 << "\n";
}
