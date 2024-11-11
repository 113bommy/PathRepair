#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
map<string, string> mp;
vector<int> vec[100];
int main() {
  int n, m;
  cin >> n >> m;
  getchar();
  for (int j = 0; j < n; j++) {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        string s1 = str.substr(0, i - 1);
        string s2 = str.substr(i, str.size() - i);
        mp[s2] = s1;
        break;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        string s1 = str.substr(0, i - 1);
        string s2 = str.substr(i, str.size() - i - 1);
        cout << str << " ";
        cout << "#" << mp[s2] << endl;
        break;
      }
    }
  }
}
