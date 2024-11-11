#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(1e5) + 123;
const long long inf = (long long)(1e18);
const int INF = (int)(1e9);
int a1, a2, a3, a4;
string s = "";
void e() {
  cout << "-1";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> a1 >> a2 >> a3 >> a4;
  if (abs(a3 - a4) > 1) e();
  if (a3 == a4 && (a1 < a3 || a2 < a3)) e();
  if (a3 > a4) {
    for (int i = 1; i <= a1 - a3; ++i) s += "4";
    for (int i = 1; i <= a3; ++i) s += "47";
    for (int i = 1; i <= a2 - a3; ++i) s += "7";
  } else if (a4 > a3) {
    s += "7";
    for (int i = 1; i <= a1 - a4; ++i) s += "4";
    for (int i = 1; i < a4 - 1; ++i) s += "74";
    for (int i = 1; i <= a2 - a4; ++i) s += "7";
    s += "4";
  } else {
    if (a1 != a3) {
      for (int i = 1; i <= a1 - a3 - 1; ++i) s += "4";
      for (int i = 1; i <= a3; ++i) s += "47";
      for (int i = 1; i <= a2 - a3; ++i) s += "7";
      s += "4";
    } else {
      for (int i = 1; i <= a3; ++i) s += "74";
      for (int i = 1; i <= a2 - a3; ++i) s += "7";
    }
  }
  for (int i = 0; i < s.size(); ++i) {
    if (i != 0) {
      if (s[i] == '4' && s[i - 1] == '7') a4--;
      if (s[i] == '7' && s[i - 1] == '4') a3--;
    }
    if (s[i] == '4') a1--;
    if (s[i] == '7') a2--;
  }
  if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0) e();
  cout << s;
  return 0;
}
