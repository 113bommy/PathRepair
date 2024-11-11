#include <bits/stdc++.h>
using namespace std;
string get_string(vector<string>& names, map<string, bool>& vis) {
  for (int i = 0; i < names.size(); i++) {
    if (vis.count(names[i]) == 0 || !vis[names[i]]) {
      return names[i];
    }
  }
  return "x";
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<string> names;
  string temp = "";
  for (char c = 'A'; c <= 'Z'; c++) {
    names.push_back(temp + c);
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    temp.push_back(c);
    for (char x = 'a'; x <= 'z'; x++) {
      temp.push_back(x);
      names.push_back(temp);
      temp.pop_back();
    }
    temp.pop_back();
  }
  int n, k;
  cin >> n >> k;
  vector<string> arr(n - k + 1);
  for (int i = 0; i < n - k + 1; i++) {
    cin >> arr[i];
  }
  map<string, bool> vis;
  vector<string> ans(n, "0");
  ans[n - 1] = get_string(names, vis);
  vis[ans[n - 1]] = true;
  for (int i = n - k; i >= 0; i--) {
    if (arr[i] == "YES") {
      for (int j = i + k - 1; j >= i; j--) {
        if (ans[j] == "0") {
          ans[j] = get_string(names, vis);
          vis[ans[j]] = true;
        }
      }
      vis[ans[i + k - 1]] = false;
    } else {
      if (ans[i + k - 2] == "0") {
        ans[i + k - 2] = ans[i + k - 1];
        vis[ans[i + k - 1]] = true;
      } else {
        ans[i] = ans[i + k - 1];
        vis[ans[i + k - 1]] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == "0") {
      ans[i] = get_string(names, vis);
      vis[ans[i]] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
