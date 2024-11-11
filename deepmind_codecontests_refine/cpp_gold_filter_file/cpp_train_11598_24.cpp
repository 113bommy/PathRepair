#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[12];
  int i, n, mark = 0;
  deque<char> s;
  scanf("%s", a);
  n = strlen(a);
  for (i = 0; i < n; i++) {
    if (mark == 3 || (mark == 0 && a[i] != '1')) {
      s.push_back(a[i]);
      mark = 3;
      continue;
    }
    if (a[i] == '1' && mark == 0) {
      s.push_back(a[i]);
      mark++;
    } else if (mark == 1) {
      if (a[i] == '4') {
        s.push_back(a[i]);
        mark++;
      } else if (a[i] != '1') {
        s.push_back(a[i]);
        mark = 3;
      }
    } else if (mark == 2) {
      if (a[i] == '1') {
        s.clear();
        s.push_back(a[i]);
        mark = 1;
      } else if (a[i] == '4') {
        s.clear();
        mark = 0;
      } else {
        s.push_back(a[i]);
        mark = 3;
      }
    }
  }
  if (mark != 3) {
    while (s.empty() != true) {
      if (s.front() == '1') {
        s.pop_front();
        if (s.empty() != true && s.front() == '4') s.pop_front();
      } else
        break;
    }
  }
  if (s.empty() != true)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
