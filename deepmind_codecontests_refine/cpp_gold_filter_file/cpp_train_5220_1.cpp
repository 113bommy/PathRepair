#include <bits/stdc++.h>
using namespace std;
int a[30];
int main() {
  string s, p, q;
  int n, i, j, k, l, m;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  for (i = 0; i < 30; i++) {
    if (a[i] >= s.size() - 1 || s.size() <= 3) {
      printf("Impossible\n");
      return 0;
    }
  }
  for (i = 1; i < s.size(); i++) {
    string x;
    for (j = i + 1; j < s.size(); j++) {
      x += s[j];
    }
    for (j = 0; j <= i; j++) {
      x += s[j];
    }
    p = x;
    reverse(p.begin(), p.end());
    if (p == x && p != s && x != s) {
      printf("1\n");
      return 0;
    }
  }
  printf("2\n");
  return 0;
}
