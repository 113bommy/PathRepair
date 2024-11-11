#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:160777216")
using namespace std;
FILE *inp, *out;
char *geolymp = "GEOLYabcdefghijkMP";
int d[10000];
int getcount(string &s) {
  int n = s.size();
  int i, j, k, m;
  for (i = 0; i < s.size(); i++) d[i] = 0;
  for (i = 0; i < s.size(); i++)
    if (s[i] == 'G') d[i] = 1;
  for (i = 1; i < 18; i++) {
    for (j = 0; j < n; j++) {
      if (s[j] == geolymp[i])
        for (k = 0; k < j; k++)
          if (s[k + 1] == s[j]) d[j] += d[k];
    }
  }
  int ret = 0;
  for (i = 0; i < s.size(); i++)
    if (s[i] == 'P') ret += d[i];
  return ret;
}
string getGeolympString(int k) {
  int i, j;
  int sum = 0;
  string s = "";
  for (i = 0; i < 8; i++) s = s + "GEOLYabcdefghijkM";
  memset(d, 0, sizeof(d));
  getcount(s);
  for (i = 0; i < s.size(); i++)
    if (s[i] == 'M' && sum + d[i] > k)
      break;
    else if (s[i] == 'M' && sum + d[i] <= k)
      sum += d[i];
  i--;
  int ans = 0;
  for (j = i; j >= 0; j--) {
    if (s[j] == 'M') {
      while (ans + sum <= k) {
        s.insert(j + 1, "P");
        ans += sum;
      }
      sum -= d[j];
    }
  }
  return s;
}
int main() {
  int k;
  cin >> k;
  cout << getGeolympString(k) << " "
       << "GEOLYabcdefghijkMP" << endl;
  return 0;
}
