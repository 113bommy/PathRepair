#include <bits/stdc++.h>
using namespace std;
bool a[1024], l;
string S;
void go() {
  int t = 0, pos = 0;
  while (pos < S.size()) {
    t = 0;
    while (pos < S.size() && S[pos] != ',') {
      t = t * 10 + S[pos] - '0';
      pos++;
    }
    a[t] = true;
    pos++;
  }
}
int main() {
  memset(a, false, sizeof(a));
  cin >> S;
  go();
  int cnt, ii;
  bool pr = false;
  for (int i = 1; i < 1024; i++) {
    if (a[i]) {
      cnt = 0;
      while (a[i]) {
        cnt++;
        i++;
      }
      if (cnt == 1) {
        if (!pr)
          printf("%d", i - 1);
        else
          printf(",%d", i - 1);
        pr = true;
      } else {
        if (!pr)
          printf("%d-%d", i - cnt, i - 1);
        else
          printf(",%d-%d", i - cnt, i - 1);
        pr = true;
      }
    }
  }
  puts("");
  return 0;
}
