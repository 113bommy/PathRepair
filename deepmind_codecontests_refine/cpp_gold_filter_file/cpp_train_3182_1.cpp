#include <bits/stdc++.h>
using namespace std;
int n, v[101], c = 0;
bool ans = true;
string s;
inline int isVowel(char x) {
  if (x == 'a') return 1;
  if (x == 'e') return 1;
  if (x == 'i') return 1;
  if (x == 'o') return 1;
  if (x == 'u') return 1;
  if (x == 'y') return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; i++) scanf(" %d ", &v[i]);
  for (long long i = 1; i <= n; i++) {
    getline(cin, s), c = 0;
    for (int j = 0; j < s.length(); j++) c += isVowel(s[j]);
    if (v[i] != c) {
      ans = false;
      break;
    }
  }
  printf("%s", ans ? "YES" : "NO");
}
