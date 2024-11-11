#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;
typedef long long int LL;
typedef unsigned long long int ULL;
LL mod = 1e9 + 7;
inline int scanInt() {
  int n = 0;
  char ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (int)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
inline LL scanLong() {
  LL n = 0;
  char ch = getchar();
  LL sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (LL)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
string gb;
LL ans = 0;
struct Trie {
  bool isEnd;
  Trie* children[26];
  Trie() {
    isEnd = false;
    for (__typeof(26) i = (0) - ((0) > (26)); i != (26) - ((0) > (26));
         i += 1 - 2 * ((0) > (26)))
      children[i] = NULL;
  }
  void addString(string s, LL pos) {
    if (pos == s.length())
      isEnd = true;
    else {
      if (children[s[pos] - 'a'] == NULL) children[s[pos] - 'a'] = new Trie();
      children[s[pos] - 'a']->addString(s, pos + 1);
    }
  }
  void solve(LL k, LL curr) {
    if (curr > k)
      return;
    else
      ans++;
    for (__typeof(26) i = (0) - ((0) > (26)); i != (26) - ((0) > (26));
         i += 1 - 2 * ((0) > (26))) {
      if (children[i] != NULL)
        children[i]->solve(k, curr + (gb[i] == '0' ? 1 : 0));
    }
  }
} root;
int main() {
  string s;
  cin >> s;
  cin >> gb;
  for (__typeof(s.length()) i = (0) - ((0) > (s.length()));
       i != (s.length()) - ((0) > (s.length()));
       i += 1 - 2 * ((0) > (s.length())))
    root.addString(s, i);
  LL k = scanLong();
  ;
  root.solve(k, 0);
  cout << ans << endl;
}
