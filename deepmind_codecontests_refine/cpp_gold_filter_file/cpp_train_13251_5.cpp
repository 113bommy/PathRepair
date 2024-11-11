#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
const long long INF = 1e9;
const long long MOD = 1e9 + 33;
int abss(int x) { return x < 0 ? -x : x; }
void no() {
  cout << -1 << "\n";
  exit(0);
}
void zero() {
  cout << 0 << "\n";
  exit(0);
}
string smaller(string &a, string &b) {
  if (a == "-" && b == "-") return "-1";
  if (a == "-") return b;
  if (b == "-") return a;
  if (a.size() < b.size())
    return a;
  else if (b.size() < a.size())
    return b;
  for (int i = 0; i < (int)a.size(); i++)
    if (a[i] < b[i])
      return a;
    else if (b[i] < a[i])
      return b;
  return a;
}
string unusedi4(string &s, int x) {
  if (x < 0) return s;
  bool bb = false;
  if (s.size() && s[0] == '7') bb = true;
  if (bb) s = s.substr(1);
  reverse(s.begin(), s.end());
  while (x--) s += "4";
  reverse(s.begin(), s.end());
  if (bb) s = "7" + s;
  return s;
}
string unusedi7(string &s, int x) {
  if (x < 0) return s;
  bool bb = false;
  if (s.size() && s[s.size() - 1] == '4') bb = true;
  if (bb) s.pop_back();
  while (x--) s += "7";
  if (bb) s += "4";
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string ans = "", ans4 = "", ans7 = "";
  int i4, i7, i47, i74;
  int u4 = 0, u7 = 0;
  int ubegin4_4 = 0, ubegin4_7 = 0;
  int ubegin7_4 = 0, ubegin7_7 = 0;
  cin >> i4 >> i7 >> i47 >> i74;
  if (i4 == 0 && i7 == 0 && i47 == 0 && i74 == 0) zero();
  if (abss(i47 - i74) > 1) no();
  if (i47 > i74) {
    u4 = u7 = i47;
    while (i47--) ans += "47";
  } else if (i74 > i47) {
    u4 = u7 = i74;
    while (i74--) ans += "74";
  } else {
    ubegin4_4 = ubegin4_7 = ubegin7_4 = ubegin7_7 = i74;
    i47 = -2;
    while (i74--) {
      ans4 += "47";
      ans7 += "74";
    }
    ans4 += "4";
    ubegin4_4++;
    ans7 += "7";
    ubegin7_7++;
  }
  if (u7 > i7 || u4 > i4) no();
  ans = unusedi4(ans, i4 - u4);
  ans = unusedi7(ans, i7 - u7);
  if (i47 == -2) {
    ans4 = unusedi4(ans4, i4 - ubegin4_4);
    ans4 = unusedi7(ans4, i7 - ubegin4_7);
    if (i4 < ubegin4_4 || i7 < ubegin4_7) ans4 = "-";
    ans7 = unusedi4(ans7, i4 - ubegin7_4);
    ans7 = unusedi7(ans7, i7 - ubegin7_7);
    if (i4 < ubegin7_4 || i7 < ubegin7_7) ans7 = "-";
    cout << smaller(ans4, ans7) << "\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
