#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> v;
  int n, k, mn = 1, mx = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  string str;
  cin >> str;
  int cnt = 1;
  sort(v.begin(), v.end(),
       [](string a, string b) { return a.size() < b.size(); });
  for (int i = 0; i < v.size(); i++) {
    if (str.size() > v[i].size()) {
      mn++;
      if (cnt == k) {
        cnt = 1;
        mn += 5;
      } else {
        cnt++;
      }
    } else
      break;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i].size() > str.size()) {
      v.erase(v.begin() + i, v.end());
      break;
    }
  }
  mx = ((v.size() - 1) / k) * 5 + v.size();
  cout << mn << " " << mx << endl;
  return 0;
}
