#include <bits/stdc++.h>
using namespace std;
char s[30];
int vis[30];
char ans[30][2];
int main() {
  cin >> s;
  int cha;
  char who;
  memset(vis, -1, sizeof(vis));
  for (int i = 0; i < 27; ++i) {
    if (vis[s[i] - 'A'] == -1)
      vis[s[i] - 'A'] = i;
    else {
      cha = i - vis[s[i] - 'A'] - 1;
      who = s[i];
      break;
    }
  }
  if (cha == 0)
    cout << "Impossible" << endl;
  else {
    if (cha & 1) {
      int tmp = cha / 2;
      int cnt = 0;
      int now = vis[who - 'A'];
      for (int i = 13 - tmp; i <= 13; ++i) {
        ans[i][1] = s[(now++) % 27];
      }
      for (int i = 13; i >= 1; --i) {
        if (s[(now) % 27] == who) {
          ++now;
          ++i;
          continue;
        }
        ans[i][2] = s[(now++) % 27];
      }
      for (int i = 1; i < 13 - tmp; ++i) {
        if (s[now % 27] == who) {
          --i;
          now++;
          continue;
        }
        ans[i][1] = s[(now++) % 27];
      }
    } else {
      int tmp = cha / 2;
      int now = vis[who - 'A'];
      for (int i = 13 - tmp; i <= 13; ++i) {
        ans[i][1] = s[(now++) % 27];
      }
      for (int i = 13; i > 13 - tmp; --i) {
        if (s[now % 27] == who) {
          ++i;
          now++;
          continue;
        }
        ans[i][2] = s[(now++) % 27];
      }
      for (int i = 13 - tmp - 1; i >= 1; --i) {
        if (s[now % 27] == who) {
          ++i;
          now++;
          continue;
        }
        ans[i][1] = s[(now++) % 27];
      }
      for (int i = 1; i <= 13 - tmp; ++i) {
        if (s[now % 27] == who) {
          --i;
          now++;
          continue;
        }
        ans[i][2] = s[(now++) % 27];
      }
    }
    for (int i = 1; i <= 13; ++i) {
      printf("%c", ans[i][1]);
    }
    printf("\n");
    for (int i = 1; i <= 13; ++i) {
      printf("%c", ans[i][2]);
    }
    printf("\n");
  }
  return 0;
}
