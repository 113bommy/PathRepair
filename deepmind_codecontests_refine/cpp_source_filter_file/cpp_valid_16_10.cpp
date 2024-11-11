#include <bits/stdc++.h>
using namespace std;
int check(string &str, int s) {
  string temp = str;
  sort(temp.begin(), temp.end());
  int ans = 0;
  for (int i = 0; i < s; i++) {
    if (str[i] == temp[i]) ans++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int s;
  string str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    cin >> str;
    int ans = check(str, s);
    cout << s - ans;
  }
  return 0;
}
