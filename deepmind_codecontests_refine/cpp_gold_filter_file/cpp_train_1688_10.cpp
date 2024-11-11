#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt[26];
    int temp[26];
    memset(cnt, 0, sizeof(cnt));
    memset(temp, 0, sizeof(temp));
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    bool flag = false;
    if (lb < la) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < la; i++) {
      cnt[a[i] - 'a']++;
      temp[a[i] - 'a']++;
    }
    int mark = -1;
    int j = 0;
    for (int i = 0; i < lb; i++) {
      for (j = i; j < lb; j++) {
        if (temp[b[j] - 'a'] != 0) {
          temp[b[j] - 'a']--;
        } else
          break;
      }
      if (j - i == la) {
        flag = true;
        break;
      } else {
        for (int k = 0; k < 26; k++) {
          temp[k] = cnt[k];
        }
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
