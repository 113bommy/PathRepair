#include <bits/stdc++.h>
const int maxn = 1005;
using namespace std;
char s[maxn], t[maxn], a[maxn];
map<char, char> mp;
int main() {
  cin.getline(s, 100);
  cin.getline(t, 100);
  for (int i = 0; i < 26; ++i) mp[s[i]] = t[i], mp[s[i] - 32] = t[i] - 32;
  cin.getline(a, 1005);
  int l = strlen(a);
  for (int i = 0; i < l; ++i) {
    if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
      cout << mp[a[i]];
    else
      cout << a[i];
  }
  cout << "\n";
  return 0;
}
