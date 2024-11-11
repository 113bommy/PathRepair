#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1, str2;
  string ans = "", ans1 = "", ans2 = "";
  cin >> str1 >> str2;
  int len = str2.length(), flag = 0;
  for (int i = 0; i < len; i++) {
    if (int(str2[i]) - int(str1[i]) > 1) {
      for (int i = 0; i < len; i++) {
        if (int(str2[i]) - int(str1[i]) > 1)
          ans += char(int(str1[i]) + 1);
        else
          ans += str1[i];
      }
      cout << ans;
      return 0;
    }
  }
  for (int i = 0; i < len; i++) {
    if (int(str2[i]) - int(str1[i]) == 1) {
      if (i == len) {
        cout << "No such string";
        return 0;
      } else {
        ans1 += str1[i];
        ans2 += str2[i];
        for (int j = i + 1; j < len; j++) {
          if (str1[j] != 'z') {
            ans1 += char(int(str1[j]) + 1);
            flag = 1;
          } else
            ans += str1[j];
        }
        if (flag == 1) {
          cout << ans1;
          return 0;
        } else {
          for (int k = i + 1; k < len; k++) {
            if (str2[k] != 'a') {
              ans2 += char(int(str2[k]) - 1);
              flag = 1;
            } else
              ans += str1[k];
          }
          if (flag == 1) {
            cout << ans2;
            return 0;
          } else {
            cout << "No such string";
            return 0;
          }
        }
      }
    } else {
      ans1 += str1[i];
      ans2 += str1[i];
    }
  }
}
