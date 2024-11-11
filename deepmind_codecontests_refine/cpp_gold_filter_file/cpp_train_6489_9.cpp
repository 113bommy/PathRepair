#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int n;
string cad;
int conv(string c) {
  int sol = 0;
  for (int i = 0; i < (int)c.length(); i++) sol = sol * 10 + c[i] - '0';
  return sol;
}
int main() {
  cin >> cad;
  int si = cad.length();
  int maxx = -1;
  for (int i = 0; i < si - 2; i++)
    for (int j = i + 1; j < si - 1; j++) {
      string s1 = cad.substr(0, i + 1);
      string s2 = cad.substr(i + 1, j - i);
      string s3 = cad.substr(j + 1, si - j);
      if ((s1[0] == '0' && s1.length() > 1) ||
          (s2[0] == '0' && s2.length() > 1) ||
          (s3[0] == '0' && s3.length() > 1))
        continue;
      if (s1.length() > 7 || s2.length() > 7 || s3.length() > 7) continue;
      int n1 = conv(s1);
      int n2 = conv(s2);
      int n3 = conv(s3);
      if (n1 > 1000000 || n2 > 1000000 || n3 > 1000000) continue;
      maxx = max(maxx, n1 + n2 + n3);
    }
  if (maxx == -1)
    printf("%d\n", -1);
  else
    printf("%d\n", maxx);
  return 0;
}
