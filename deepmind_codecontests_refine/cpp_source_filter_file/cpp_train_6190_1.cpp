#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 3;
int n, p, l;
string s;
int str[maxN], nstr[maxN];
void input() {
  cin >> n >> p;
  cin >> s;
  l = s.length();
  for (int i = 0; i < l; ++i) str[i] = s[i] - 'a';
}
bool check(int x) {
  for (int i = 0; i < l; ++i) nstr[i] = str[i];
  while (1) {
    nstr[x]++;
    if (nstr[x] == p) return 0;
    if (x - 1 >= 0)
      if (nstr[x] == nstr[x - 1]) continue;
    if (x - 2 >= 0)
      if (nstr[x] == nstr[x - 2]) continue;
    break;
  }
  for (int i = x + 1; i < l; ++i) {
    nstr[i] = 0;
    while (1) {
      if (i - 2 >= 0)
        if (nstr[i] == nstr[i - 2]) {
          nstr[i]++;
          if (nstr[i] == p) return 0;
          continue;
        }
      if (i - 1 >= 0)
        if (nstr[i] == nstr[i - 2]) {
          nstr[i]++;
          if (nstr[i] == p) return 0;
          continue;
        }
      break;
    }
  }
  for (int i = 0; i < l; ++i) cout << (char)(nstr[i] + 'a');
  cout << "\n";
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  for (int i = l - 1; i >= 0; --i) {
    if (check(i)) {
      return 0;
    }
  }
  cout << "NO\n";
}
