#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 69;
char bb[MX], aa[MX], ans[MX];
int fre[55], fre2[55];
int main() {
  scanf("%s", bb);
  scanf("%s", aa);
  int sz1 = strlen(bb);
  for (int i = 0; i < sz1; i++) {
    fre[bb[i] - 'a']++;
  }
  int temp = (sz1) / 2;
  for (int j = 'z' - 'a'; j >= 0; j--)
    while (fre[j] != 0 && temp != 0) {
      fre[j]--;
      temp--;
    }
  int sz2 = strlen(aa);
  for (int i = 0; i < sz2; i++) {
    fre2[aa[i] - 'a']++;
  }
  temp = (sz1 + 1) / 2;
  for (int j = 0; j <= 'z'; j++)
    while (fre2[j] && temp) {
      fre2[j]--;
      temp--;
    }
  int f = 0, l = sz1 - 1;
  for (int i = 0; i < sz1; i++) {
    int big1 = -1, sm1 = -1, big2 = -1, sm2 = -1;
    for (int j = 'z' - 'a'; j >= 0; j--) {
      if (fre2[j]) {
        if (big1 == -1) big1 = j;
        sm2 = j;
      }
    }
    for (int j = 0; j <= 'z' - 'a'; j++) {
      if (fre[j]) {
        if (sm1 == -1) sm1 = j;
        big2 = j;
      }
    }
    if (i % 2 == 0) {
      if (big1 <= sm1) {
        ans[l] = big2 + 'a';
        l--;
        fre[big2]--;
      } else {
        ans[f] = sm1 + 'a';
        fre[sm1]--;
        f++;
      }
    } else {
      if (sm1 >= big1) {
        ans[l] = sm2 + 'a';
        fre2[sm2]--;
        l--;
      } else {
        ans[f] = big1 + 'a';
        fre2[big1]--;
        f++;
      }
    }
  }
  printf("%s", ans);
  return 0;
}
