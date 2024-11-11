#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const double PI = acos(-1.0);
char rev(char c) { return c == '0' ? '1' : '0'; }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
      if (i > 0 && s[i] != t[i] && s[i - 1] != t[i - 1]) {
        if (s[i] == s[i - 1]) {
          ans.push_back(i + 1);
          ans.push_back(2);
          ans.push_back(i + 1);
          s[i] = t[i];
          s[i - 1] = t[i - 1];
        } else {
          if (i == 1) {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(1);
            s[i] = t[i];
            s[i - 1] = t[i - 1];
          } else if (s[i - 2] == t[i - 2]) {
            ans.push_back(i + 1);
            ans.push_back(1);
            ans.push_back(i + 1);
            ans.push_back(i);
            ans.push_back(1);
            ans.push_back(i);
            s[i] = t[i];
            s[i - 1] = t[i - 1];
          } else if (s[i] == s[i - 2]) {
            ans.push_back(i + 1);
            ans.push_back(3);
            ans.push_back(i + 2);
            s[i - 1] = t[i - 1];
            swap(s[i - 2], s[i]);
            s[i] = rev(s[i]);
            s[i - 2] = rev(s[i - 2]);
          } else if (s[i] != t[i - 2]) {
            ans.push_back(i + 1);
            ans.push_back(3);
            ans.push_back(i + 2);
            ans.push_back(i + 1);
            ans.push_back(1);
            ans.push_back(i + 1);
            s[i] = t[i];
            s[i - 1] = t[i - 1];
            s[i - 2] = t[i - 2];
          } else {
            ans.push_back(i);
            ans.push_back(2);
            ans.push_back(i);
            ans.push_back(i + 1);
            ans.push_back(1);
            ans.push_back(i + 1);
            s[i] = t[i];
            s[i - 1] = t[i - 1];
            s[i - 2] = t[i - 2];
          }
        }
      } else if (s[i] != t[i]) {
        if (i == 0) {
          ans.push_back(1);
        } else {
          ans.push_back(i + 1);
          ans.push_back(1);
          ans.push_back(i + 1);
        }
        s[i] = t[i];
      }
    }
    cout << ans.size();
    for (int x : ans) cout << " " << x;
    cout << endl;
  }
  return 0;
}
