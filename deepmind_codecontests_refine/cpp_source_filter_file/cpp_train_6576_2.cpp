#include <bits/stdc++.h>
using namespace std;
int ch[27], ch2[27], ch3[27];
int main() {
  int q;
  cin >> q;
  while (q--) {
    memset(ch, 0, sizeof(ch));
    memset(ch, 0, sizeof(ch2));
    memset(ch, 0, sizeof(ch3));
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    int k = 0;
    bool flag = 0;
    for (int i = 0; i < len2; i++) {
      ch2[s2[i] - 'a']++;
      if (s1[k] == s2[i] && k < len1) {
        ch[s1[k] - 'a']++;
        k++;
      }
      if (i == len2 - 1) {
        if (k == len1) {
          flag = 1;
        }
      }
    }
    if (!flag) {
      cout << "NO" << endl;
    } else {
      bool f = 1;
      for (int i = 0; i < len3; i++) {
        ch3[s3[i] - 'a']++;
      }
      for (int i = 0; i < 27; i++) {
        if (ch[i] + ch3[i] < ch2[i]) {
          cout << "NO" << endl;
          f = 0;
          break;
        }
      }
      if (f) {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
