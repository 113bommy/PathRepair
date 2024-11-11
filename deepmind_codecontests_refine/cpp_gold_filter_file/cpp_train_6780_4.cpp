#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
string s, vas;
long long k, suur;
bool b;
int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  cin >> k;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != '?' && s[i] != '*') suur++;
  if (suur < k) {
    for (int i = 0; i < s.size(); i++)
      if (s[i] != '?' && s[i] != '*')
        vas += s[i];
      else if (s[i] == '*') {
        for (int j = 0; j < (k - suur); j++) vas += s[i - 1];
        suur = k;
      }
  } else if (suur == k) {
    for (int i = 0; i < s.size(); i++)
      if (s[i] != '?' && s[i] != '*') vas += s[i];
  } else
    for (int i = 0; i < s.size(); i++)
      if (s[i] != '?' && s[i] != '*')
        if (i == s.size() - 1 || (s[i + 1] != '?' && s[i + 1] != '*') ||
            suur == k)
          vas += s[i];
        else
          suur--;
  if (suur == k)
    cout << vas;
  else
    cout << "Impossible";
}
