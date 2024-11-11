#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, v1 = "", v2 = "";
  int i = 0, v1i = -1, v2i = -1;
  char c;
  int *a = new int[26];
  for (i = 0; i < 26; i++) a[i] = 0;
  cin >> s;
  for (i = 0; i < 27; i++) {
    if (a[s[i] - 'A'] == 1) c = s[i];
    a[s[i] - 'A']++;
  }
  for (i = 0; i < 27; i++)
    if (s[i] == c)
      if (v1i != -1) {
        v2i = i;
        break;
      } else
        v1i = i;
  if (v2i - v1i == 1) {
    cout << "Impossible";
    return 0;
  }
  if (int((v2i + v1i) / 2.0f) < 12) {
    reverse(s.begin(), s.end());
    v1i = -1;
    v2i = -1;
    for (i = 0; i < 27; i++)
      if (s[i] == c)
        if (v1i != -1) {
          v2i = i;
          break;
        } else
          v1i = i;
  }
  if ((v2i + v1i) % 2)
    for (i = 0; i <= int((v2i + v1i) / 2.0f); i++) v1 += s[i];
  else
    for (i = 0; i < int((v2i + v1i) / 2.0f); i++) v1 += s[i];
  for (; i < 27; i++)
    if (s[i] != c) v2 = s[i] + v2;
  if (v1.length() != v2.length()) {
    while (v2.length() < v1.length()) {
      v2 = v1[0] + v2;
      v1.erase(v1.begin());
    }
    while (v1.length() > v2.length()) {
      v1 = v2[0] + v1;
      v2.erase(v2.begin());
    }
  }
  cout << v1 << endl << v2 << endl;
  return 0;
}
