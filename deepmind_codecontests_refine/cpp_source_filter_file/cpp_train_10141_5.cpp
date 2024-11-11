#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main() {
  cin >> s;
  char c = s[0], num = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == c)
      num++;
    else {
      a.push_back(num);
      c = s[i];
      num = 1;
    }
  }
  if (c == s[0])
    a[0] += num;
  else
    a.push_back(num);
  int st = -1;
  for (int i = 0; i < a.size(); i++)
    if (a[i] > 1) {
      st = i;
      break;
    }
  if (st == -1) {
    cout << (a.size()) / 2 << endl;
  } else {
    int ans = 0;
    int key = st;
    st = (st + 1) % a.size();
    while (st != key) {
      int num = 0;
      while (a[st] == 1) {
        num++;
        st = (st + 1) % a.size();
      }
      ans += num / 2;
      ans++;
      if (st == key) break;
      st = (st + 1) % a.size();
    }
    cout << ans << endl;
  }
  return 0;
}
