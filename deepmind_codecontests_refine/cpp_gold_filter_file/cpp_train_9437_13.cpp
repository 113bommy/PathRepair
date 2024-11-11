#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  string str;
  int cnt[30] = {0};
  int f = 0, c1 = 0, c2 = 0;
  set<char> s;
  cin >> str;
  if (str.size() <= 3) f = 1;
  for (int i = 0; i < str.size(); i++) cnt[str[i] - 'a']++, s.insert(str[i]);
  for (int i = 0; i <= 26; i++) {
    if (cnt[i] >= 2) c2++;
  }
  if (s.size() == 1 || s.size() >= 5)
    f = 1;
  else if (s.size() == 2) {
    if (c2 < 2) f = 1;
  } else if (s.size() == 3) {
    if (c2 == 0) f = 1;
  }
  if (f == 1)
    cout << "No";
  else
    cout << "Yes" << endl;
  return 0;
}
