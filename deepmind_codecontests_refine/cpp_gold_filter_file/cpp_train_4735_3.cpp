#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int j = 0;
  bool ok = false;
  int l;
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == s1[j]) j++;
    if (j == s1.size()) {
      ok = true;
      l = i;
      break;
    }
  }
  if (!ok) {
    printf("0");
    return 0;
  }
  ok = false;
  int b = s1.size() - 1;
  int start = l;
  for (int i = s2.size() - 1; i > 0; i--) {
    if (s2[i] == s1[b]) b--;
    if (b == -1) {
      ok = true;
      start = i;
      break;
    }
  }
  if (!ok || start <= l) {
    printf("0");
    return 0;
  }
  printf("%d", start - l);
  return 0;
}
