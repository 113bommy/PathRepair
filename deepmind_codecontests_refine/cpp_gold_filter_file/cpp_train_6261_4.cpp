#include <bits/stdc++.h>
using namespace std;
char s[500050], ss[500050];
int s_x[2];
int ss_x[2];
string ans;
int Next[500050];
void GETNext(string str) {
  int a = str.size();
  str += "6666";
  Next[0] = 0, Next[1] = 0;
  for (int i = 1; i < a; i++) {
    int j = Next[i];
    while (j && str[i] != str[j]) j = Next[j];
    Next[i + 1] = str[i] == str[j] ? j + 1 : 0;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  ;
  cin >> s >> ss;
  GETNext(ss);
  int len_s = strlen(s);
  for (int i = 0; i < len_s; i++) {
    s_x[s[i] == '1']++;
  }
  int len_ss = strlen(ss);
  for (int i = 0; i < Next[len_ss]; i++) {
    ss_x[ss[i] == '1']++;
    ans += ss[i];
  }
  s_x[0] -= ss_x[0];
  s_x[1] -= ss_x[1];
  if (s_x[0] >= 0 && s_x[1] >= 0) {
    cout << ans;
  } else {
    s_x[0] += ss_x[0];
    s_x[1] += ss_x[1];
    Next[len_ss] = 0;
  }
  ss_x[0] = 0;
  ss_x[1] = 0;
  int len_sss = len_ss;
  len_ss = strlen(ss + Next[len_ss]);
  for (int i = 0; i < len_ss; i++) {
    ss_x[(ss + Next[len_sss])[i] == '1']++;
  }
  int ans_l;
  if (ss_x[0] == 0) {
    ans_l = s_x[1] / ss_x[1];
  } else if (ss_x[1] == 0) {
    ans_l = s_x[0] / ss_x[0];
  } else {
    ans_l = min(s_x[1] / ss_x[1], s_x[0] / ss_x[0]);
  }
  for (int i = 0; i < ans_l; i++) {
    cout << ss + Next[len_sss];
  }
  s_x[1] -= ss_x[1] * ans_l;
  s_x[0] -= ss_x[0] * ans_l;
  for (int i = 0; i < s_x[0]; i++) {
    cout << '0';
  }
  for (int i = 0; i < s_x[1]; i++) {
    cout << '1';
  }
  return 0;
}
