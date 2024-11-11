#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9 + 5;
const long long MOD = (long long)1e9 + 7;
char diff(string s1, string s2) {
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      return s2[i];
    }
  }
  return s2.back();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string ans;
  multiset<string> all;
  cin >> n;
  cout << "? 1 " << n << endl;
  if (n == 1) {
    cin >> ans;
    cout << ans << '\n';
    return 0;
  }
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    string second;
    cin >> second;
    sort(second.begin(), second.end());
    all.insert(second);
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string second;
    cin >> second;
    sort(second.begin(), second.end());
    all.erase(all.find(second));
  }
  string str[105];
  for (const string &second : all) {
    str[second.size()] = second;
  }
  for (int i = 0; i < n; i++) {
    ans.push_back(diff(str[i], str[i + 1]));
  }
  cout << "! " << ans << '\n';
  return 0;
}
