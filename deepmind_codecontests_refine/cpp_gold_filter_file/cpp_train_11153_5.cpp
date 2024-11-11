#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
  cin >> l;
  string s, p, q, r, t, u, v;
  cin >> s;
  p = q = r = t = u = v = s;
  char str1[200004], str2[200004], str3[200004], str4[200004], str5[200004],
      str6[200004];
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str1[i] = 'R';
    else if (i % 3 == 1)
      str1[i] = 'G';
    else
      str1[i] = 'B';
  }
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str2[i] = 'G';
    else if (i % 3 == 1)
      str2[i] = 'B';
    else
      str2[i] = 'R';
  }
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str3[i] = 'B';
    else if (i % 3 == 1)
      str3[i] = 'R';
    else
      str3[i] = 'G';
  }
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str4[i] = 'R';
    else if (i % 3 == 1)
      str4[i] = 'B';
    else
      str4[i] = 'G';
  }
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str5[i] = 'G';
    else if (i % 3 == 1)
      str5[i] = 'R';
    else
      str5[i] = 'B';
  }
  for (i = 0; i < 200001; i++) {
    if (i % 3 == 0)
      str6[i] = 'B';
    else if (i % 3 == 1)
      str6[i] = 'G';
    else
      str6[i] = 'R';
  }
  str1[i] = str2[i] = str3[i] = str4[i] = str5[i] = str6[i] = '\0';
  for (i = 0; i < l; i++) {
    if (s[i] != str1[i]) {
      one++;
      p[i] = str1[i];
    } else
      p[i] = s[i];
  }
  for (i = 0; i < l; i++) {
    if (s[i] != str2[i]) {
      two++;
      q[i] = str2[i];
    } else
      q[i] = s[i];
  }
  for (i = 0; i < l; i++) {
    if (s[i] != str3[i]) {
      three++;
      r[i] = str3[i];
    } else {
      r[i] = s[i];
    }
  }
  for (i = 0; i < l; i++) {
    if (s[i] != str4[i]) {
      four++;
      t[i] = str4[i];
    } else
      t[i] = s[i];
  }
  for (i = 0; i < l; i++) {
    if (s[i] != str5[i]) {
      five++;
      u[i] = str5[i];
    } else
      u[i] = s[i];
  }
  for (i = 0; i < l; i++) {
    if (s[i] != str6[i]) {
      six++;
      v[i] = str6[i];
    } else
      v[i] = s[i];
  }
  int ans = min(one, two);
  ans = min(ans, three);
  ans = min(ans, four);
  ans = min(ans, five);
  ans = min(ans, six);
  cout << ans << "\n";
  if (ans == one)
    cout << p << '\n';
  else if (ans == two)
    cout << q << "\n";
  else if (ans == three)
    cout << r << "\n";
  else if (ans == four)
    cout << t << "\n";
  else if (ans == five)
    cout << u << "\n";
  else
    cout << v << "\n";
  return 0;
}
