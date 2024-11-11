#include <bits/stdc++.h>
using namespace std;
char alp[28];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    alp[str.at(i) - 'a']++;
  }
  string ans;
  for (int i = 0; i < 28; i++) {
    while (alp[i] != 0) {
      ans += i + 'a';
      alp[i]--;
    }
  }
  cout << ans;
}
