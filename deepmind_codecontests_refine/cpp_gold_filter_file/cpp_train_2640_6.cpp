#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char s[MAXN], t[MAXN];
int can_r[MAXN], can_l[MAXN];
vector<int> pos[30];
int main() {
  ;
  scanf("%s %s", s, t);
  int sl = strlen(s), tl = strlen(t);
  for (int i = 0, ti = 0; i < sl; i++) {
    can_l[i] = i ? can_l[i - 1] : 0;
    if (ti < tl && t[ti] == s[i]) can_l[i]++, ti++;
  }
  for (int i = sl - 1, ti = tl - 1; i >= 0; i--) {
    can_r[i] = i < sl - 1 ? can_r[i + 1] : 0;
    if (ti >= 0 && t[ti] == s[i]) can_r[i]++, ti--;
  }
  bool glob_good = true;
  for (int i = 0; i < tl; i++) pos[t[i] - 'a'].push_back(i);
  for (int i = 0; i < sl; i++) {
    bool good = false;
    if ((int)pos[s[i] - 'a'].size() >= 1) {
      int le = 0, ri = (int)pos[s[i] - 'a'].size() - 1;
      while (le != ri) {
        int m = (le + ri) >> 1;
        if (can_l[i] >= pos[s[i] - 'a'][m] + 1 &&
            can_r[i] >= tl - pos[s[i] - 'a'][m]) {
          good = true;
          break;
        }
        if (can_l[i] < pos[s[i] - 'a'][m] + 1)
          ri = m;
        else
          le = m + 1;
      }
      if (can_l[i] >= pos[s[i] - 'a'][le] + 1 &&
          can_r[i] >= tl - pos[s[i] - 'a'][le])
        good = true;
    }
    if (!good) {
      glob_good = false;
      break;
    }
  }
  printf("%s\n", glob_good ? "Yes" : "No");
  ;
  return 0;
}
