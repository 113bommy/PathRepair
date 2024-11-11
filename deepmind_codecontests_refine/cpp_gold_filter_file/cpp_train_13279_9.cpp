#include <bits/stdc++.h>
using namespace std;
map<string, int> mapi;
map<int, string> inv;
vector<vector<int> > vec(100);
int a[12], haha[12];
int ans[123456];
int main() {
  std::ios::sync_with_stdio(false);
  int i;
  for (i = 0; i < 6; i++) {
    cin >> a[i];
  }
  mapi["S"] = 0;
  mapi["M"] = 1;
  mapi["L"] = 2;
  mapi["XL"] = 3;
  mapi["XXL"] = 4;
  mapi["XXXL"] = 5;
  int n;
  cin >> n;
  map<string, int>::iterator it;
  for (it = mapi.begin(); it != mapi.end(); it++) {
    inv[it->second] = it->first;
  }
  string s, str;
  int val, j, flag, val1;
  for (j = 0; j < n; j++) {
    cin >> s;
    val = s.find(',');
    str = "";
    for (i = val + 1; i < s.length(); i++) {
      str += s[i];
    }
    val1 = mapi[str];
    flag = 0;
    str = "";
    for (i = 0; i < val; i++) {
      flag = 1;
      str += s[i];
    }
    if (flag) {
      val1 = min(val1, mapi[str]);
      haha[val1]++;
      vec[val1].push_back(j);
    } else {
      if (!a[val1]) {
        cout << "NO" << endl;
        return 0;
      }
      a[val1]--;
      ans[j] = val1;
    }
  }
  for (i = 0; i < 5; i++) {
    j = 0;
    while (haha[i] > 0) {
      if (a[i] > 0) {
        ans[vec[i][j]] = i;
        a[i]--;
      } else if (a[i + 1]) {
        ans[vec[i][j]] = i + 1;
        a[i + 1]--;
      } else {
        cout << "NO" << endl;
        return 0;
      }
      haha[i]--;
      j++;
    }
  }
  cout << "YES" << endl;
  for (i = 0; i < n; i++) {
    cout << inv[ans[i]] << endl;
  }
  return 0;
}
