#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int main() {
  string s, t;
  cin >> s >> t;
  int l[MAXN], r[MAXN];
  int num[26];
  int len_s = s.size(), len_t = t.size();
  memset(num, -1, sizeof num);
  int pos = 0;
  for (int i = 0; i < len_s; i++) {
    if (t[pos] == s[i]) pos++;
    l[i] = pos - 1;
  }
  pos = len_t - 1;
  for (int i = len_s - 1; i >= 0; i--) {
    if (pos >= 0 && t[pos] == s[i]) pos--;
    r[i] = pos + 1;
  }
  bool flag = true;
  for (int i = 0; i < len_s; i++) {
    if (l[i] > 0) num[t[l[i]] - 'a'] = l[i];
    if (num[s[i] - 'a'] == -1 || num[s[i] - 'a'] < r[i]) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
