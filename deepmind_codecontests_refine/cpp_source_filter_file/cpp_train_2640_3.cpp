#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int Maxl[2 * 100000], Maxr[2 * 100000];
int latest[2 * 100000];
int main() {
  cin >> s1 >> s2;
  int len1, len2;
  len1 = s1.size(), len2 = s2.size();
  memset(Maxl, 0, sizeof Maxl);
  memset(Maxr, 0, sizeof Maxr);
  memset(latest, 0, sizeof latest);
  int cnt = 0, j = 0;
  for (int i = 0; i < len1; ++i) {
    if (j < len2 && s1[i] == s2[j]) {
      Maxl[i] = ++j;
      latest[s1[i]] = j;
    } else {
      Maxl[i] = latest[s1[i]];
    }
  }
  j = len2 - 1, cnt = 0;
  memset(latest, 0, sizeof latest);
  for (int i = len1 - 1; i >= 0; --i) {
    if (j < len2 && s1[i] == s2[j]) {
      Maxr[i] = ++cnt;
      latest[s1[i]] = cnt;
      --j;
    } else {
      Maxr[i] = latest[s1[i]];
    }
  }
  bool flag = true;
  for (int i = 0; i < len1; ++i) {
    if (Maxl[i] + Maxr[i] < len2) {
      flag = false;
      break;
    }
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
