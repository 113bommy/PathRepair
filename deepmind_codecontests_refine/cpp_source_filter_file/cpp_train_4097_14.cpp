#include <bits/stdc++.h>
using namespace std;
char s[100005];
int ar[30];
deque<int> pos[30];
int now;
int len;
int main() {
  for (int i = 0; i < 30; i++) pos[i].clear();
  memset(ar, 0, sizeof(ar));
  scanf("%s", s);
  len = strlen(s);
  for (int i = 0; i < len; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  now = 0;
  for (int i = 25; i >= 0; i--) {
    while (!pos[i].empty()) {
      if (now < pos[i].front()) {
        printf("%c", (char)(i + 'a'));
        now = pos[i].front();
      }
      pos[i].pop_front();
    }
  }
  return 0;
}
