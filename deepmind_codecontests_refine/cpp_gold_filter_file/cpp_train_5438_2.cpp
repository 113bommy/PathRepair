#include <bits/stdc++.h>
using namespace std;
string s[] = {"H",  "HE", "LI", "BE", "B",  "C",  "N",  "O",  "F",  "NE", "NA",
              "MG", "AL", "SI", "P",  "S",  "CL", "AR", "K",  "CA", "SC", "TI",
              "V",  "CR", "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS",
              "SE", "BR", "KR", "RB", "SR", "Y",  "ZR", "NB", "MO", "TC", "RU",
              "RH", "PD", "AG", "CD", "IN", "SN", "SB", "TE", "I",  "XE", "CS",
              "BA", "LA", "CE", "PR", "ND", "PM", "SM", "EU", "GD", "TB", "DY",
              "HO", "ER", "TM", "YB", "LU", "HF", "TA", "W",  "RE", "OS", "IR",
              "PT", "AU", "HG", "TL", "PB", "BI", "PO", "AT", "RN", "FR", "RA",
              "AC", "TH", "PA", "U",  "NP", "PU", "AM", "CM", "BK", "CF", "ES",
              "FM", "MD", "NO", "LR", "RF", "DB", "SG", "BH", "HS", "MT", "DS",
              "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG"};
string ss;
int dfs(int now) {
  int i;
  int t = 0;
  if (now >= ss.length()) return 1;
  for (i = 0; i < 118; i++)
    if (s[i][0] == ss[now])
      if (s[i].length() == 1)
        t |= dfs(now + 1);
      else
        t |= ss.length() > now + 1 && s[i][1] == ss[now + 1] && dfs(now + 2);
  return t;
}
int main() {
  cin >> ss;
  printf("%s\n", dfs(0) ? "YES" : "NO");
  return 0;
}
