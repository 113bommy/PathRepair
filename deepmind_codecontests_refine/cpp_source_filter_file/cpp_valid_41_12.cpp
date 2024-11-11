#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
string s;
int n, m;
long long a[N], sum1[N], b[N], sum2[N], sum3[N], sum4[N], sum5[N], sum6[6];
string s1, s2, s3, s4, s5, s6;
void init() {
  string s11 = "abc", s12 = "acb", s13 = "bca", s14 = "bac", s15 = "cab",
         s16 = "cba";
  for (int i = 1; i <= N / 3 + 1; i++) {
    s1 += s11;
    s2 += s12;
    s3 += s13;
    s4 += s14;
    s5 += s15;
    s6 += s16;
  }
}
void init1() {
  int l, r, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s1[j])
      sum1[j] = sum1[j - 1] + 1;
    else
      sum1[j] = sum1[j - 1];
  }
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s2[j])
      sum2[j] = sum2[j - 1] + 1;
    else
      sum2[j] = sum2[j - 1];
  }
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s3[j])
      sum3[j] = sum3[j - 1] + 1;
    else
      sum3[j] = sum3[j - 1];
  }
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s4[j])
      sum4[j] = sum4[j - 1] + 1;
    else
      sum4[j] = sum4[j - 1];
  }
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s5[j])
      sum5[j] = sum5[j - 1] + 1;
    else
      sum5[j] = sum5[j - 1];
  }
  for (int i = 1, j = 1; j <= n; j++) {
    if (s[j] != s6[j])
      sum6[j] = sum6[j - 1] + 1;
    else
      sum6[j] = sum6[j - 1];
  }
}
void Test() {
  s.clear();
  init();
  cin >> n >> m;
  string ss;
  s += "0";
  cin >> ss;
  s += ss;
  init1();
  while (m--) {
    int l, r, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
    cin >> l >> r;
    long long ans = 0x3f3f3f3f;
    ans = min(sum1[r] - sum1[l - 1], ans);
    ans = min(sum2[r] - sum2[l - 1], ans);
    ans = min(sum3[r] - sum3[l - 1], ans);
    ans = min(sum4[r] - sum4[l - 1], ans);
    ans = min(sum5[r] - sum5[l - 1], ans);
    ans = min(sum6[r] - sum6[l - 1], ans);
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  Test();
}
