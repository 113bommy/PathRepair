#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int l, z;
vector<pair<char, int> > vv;
char s[1001000];
int main() {
  cin.getline(s, 1001000);
  l = strlen(s) - 1;
  if (l % 2 == 0)
    z = l / 2 - 1;
  else
    z = l / 2;
  for (int i = 0; i <= z; i++) swap(s[i], s[l - i]);
  int say = 0;
  for (int i = 0; i <= l; i++) {
  ww:
    if (s[i] == '1' && s[i + 1] == '1') {
      z = 0;
      say++;
      vv.push_back(make_pair('+', i));
      for (int j = i + 2; j <= l; j++)
        if (s[j] == '0') {
          z = j;
          s[j] = '1';
          break;
        }
      if (z != 0)
        i = z;
      else {
        i = l + 1;
        vv.push_back(make_pair('-', l + 1));
        say++;
      }
      goto ww;
    } else if (s[i] == '1') {
      say++;
      vv.push_back(make_pair('-', i));
    }
  }
  cout << say << endl;
  l = vv.size() - 1;
  for (int i = 0; i <= l; i++)
    cout << vv[i].first << "2^" << vv[i].second << endl;
  return EXIT_SUCCESS;
}
