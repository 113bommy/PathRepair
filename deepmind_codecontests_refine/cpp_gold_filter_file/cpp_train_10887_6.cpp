#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  vector<string> vec;
  for (int i = 0; i < n; i++) vec.push_back("A");
  vector<char> v;
  for (char i = 'A'; i <= 'Z'; i++) v.push_back(i);
  int index = 0;
  for (int i = 0; i < n - k + 1; i++) {
    string str;
    cin >> str;
    if (str == "NO") {
      string tmp = vec[i];
      vec[i + (k - 1)] = tmp;
    } else if (str == "YES") {
      unordered_map<string, int> mp;
      for (int j = i; j < (i + k); j++) {
        if (mp[vec[j]]) {
          string tmp = vec[j];
          while (mp[tmp]) {
            tmp += 'a';
            if (tmp.size() > 10) {
              index++;
              if (index >= v.size()) {
                index = 0;
                tmp = v[index];
                tmp += 'b';
              }
              tmp = v[index];
            }
          }
          vec[j] = tmp;
        }
        mp[vec[j]]++;
      }
    }
  }
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
  cout << '\n';
}
