#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int arr[26];
    for (int i = 0; i < 26; i++) {
      arr[i] = 0;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      arr[s[i] - 'a']++;
      if (arr[i] > 1) {
        flag = 1;
        cout << "No" << endl;
        break;
      }
    }
    if (flag == 1) {
      continue;
    }
    vector<int> v;
    int start = 0;
    for (int i = 0; i < 26; i++) {
      if (start != arr[i]) {
        start = arr[i];
        v.push_back(start);
      }
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 1) {
        cnt++;
      }
    }
    if (cnt == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
