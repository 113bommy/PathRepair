#include <bits/stdc++.h>
using namespace std;
bool vow(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, j;
  cin >> n;
  string arr[100005];
  for (i = 0; i < n; i++) cin >> arr[i];
  map<pair<int, char>, vector<string> > mp;
  map<pair<int, char>, int> mpcnt;
  map<int, int> mpl;
  map<int, vector<string> > m2;
  char c;
  for (i = 0; i < n; i++) {
    int l = arr[i].length(), cnt = 0;
    for (j = 0; j < l; j++) {
      if (vow(arr[i][j])) {
        c = arr[i][j];
        ++cnt;
      }
    }
    mp[{cnt, c}].push_back(arr[i]);
    mpcnt[{cnt, c}]++;
  }
  vector<string> v1, v2;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    vector<string> temp;
    temp = it->second;
    int n = temp.size();
    if (n % 2 == 0) {
      for (i = 0; i < n; i++) v1.push_back(temp[i]);
    } else {
      for (i = 0; i < n - 1; i++) v1.push_back(temp[i]);
      m2[(it->first).first].push_back(temp[n - 1]);
    }
  }
  for (auto it = m2.begin(); it != m2.end(); it++) {
    vector<string> temp = it->second;
    int n = temp.size();
    if (n % 2 != 0) --n;
    for (i = 0; i < n; i++) v2.push_back(temp[i]);
  }
  int n1 = v1.size(), n2 = v2.size();
  n = min(n1, n2);
  vector<pair<pair<string, string>, pair<string, string> > > ans;
  for (i = 0; i < n - 1; i += 2)
    ans.push_back({{v1[i], v2[i]}, {v1[i + 1], v2[i + 1]}});
  for (int j = i; j < n1 - 3; j += 4)
    ans.push_back({{v1[j], v1[j + 2]}, {v1[j + 1], v1[j + 3]}});
  cout << ans.size() << "\n";
  for (i = 0; i < ans.size(); i++)
    cout << ans[i].first.first << " " << ans[i].first.second << "\n"
         << ans[i].second.first << " " << ans[i].second.second << "\n";
}
