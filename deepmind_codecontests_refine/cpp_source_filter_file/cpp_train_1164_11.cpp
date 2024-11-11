#include <bits/stdc++.h>
using namespace std;
int pre1, pre2, pre3, n, k;
char str1[100005], str2[100005], str3[100005];
bool change1() {
  for (int i = max(pre1, 0); i < n - 1; i++) {
    if (str1[i] == '4' && str1[i + 1] == '7') {
      if (i % 2 == 1)
        str1[i] = '7', pre1 = i - 1;
      else
        str1[i + 1] = '4', pre1 = i + 1;
      return true;
    }
  }
  return false;
}
bool change2() {
  for (int i = max(pre2, 0); i < n - 1; i++) {
    if (str2[i] == '4' && str2[i + 1] == '7') {
      if (i % 2 == 1)
        str2[i] = '7', pre2 = i - 1;
      else
        str2[i + 1] = '4', pre2 = i + 1;
      return true;
    }
  }
  return false;
}
bool change3() {
  for (int i = max(pre3, 0); i < n - 1; i++) {
    if (str3[i] == '4' && str3[i + 1] == '7') {
      if (i % 2 == 1)
        str3[i] = '7', pre3 = i - 1;
      else
        str3[i + 1] = '4', pre3 = i + 1;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d%s", &n, &k, str1);
  strcpy(str2, str1);
  pre1 = pre2 = pre3 = 0;
  bool flag = true;
  while (k) {
    if (!change1()) break;
    if (flag) {
      if (change2()) {
        if (change2())
          ;
        else
          flag = false;
      } else
        flag = false;
    }
    k--;
    if (strcpy(str1, str2) == 0 && flag) {
      flag = false;
      int len = 0;
      strcpy(str3, str1);
      while (true) {
        change3();
        len++;
        if (strcpy(str3, str1) == 0) break;
      }
      k %= len;
    }
  }
  printf("%s\n", str1);
  return 0;
}
