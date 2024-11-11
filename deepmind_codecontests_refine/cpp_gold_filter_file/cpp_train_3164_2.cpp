#include <bits/stdc++.h>
using namespace std;
int h, w, k;
int mp1[1005][1005], mp2[1005][1005], ans[1005][1005];
int main() {
  cin >> h >> w >> k;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < w; j++) {
      char x = getchar();
      while (!isalpha(x)) x = getchar();
      if (x == 'E')
        mp1[i][j] = 1;
      else
        mp1[i][j] = 0;
    }
    if (i != h) {
      for (int j = 1; j <= w; j++) {
        char x = getchar();
        while (!isalpha(x)) x = getchar();
        if (x == 'E')
          mp2[i][j] = 1;
        else
          mp2[i][j] = 0;
      }
    }
  }
  if (k == 1) {
    int ans = 0, tot = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j < w; j++) {
        if (mp1[i][j] == 1) ans++;
        tot++;
      }
    }
    for (int i = 1; i < h; i++) {
      for (int j = 1; j <= w; j++) {
        if (mp2[i][j] == 1) ans++;
        tot++;
      }
    }
    if (ans * 4 >= tot * 3) {
      puts("YES");
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
          putchar('1');
          putchar(' ');
        }
        puts("");
      }
      return 0;
    } else {
      puts("NO");
      return 0;
    }
  }
  if (h <= w) {
    ans[1][1] = 0;
    for (int i = 2; i <= w; i++) {
      if (mp1[1][i - 1] == 0)
        ans[1][i] = ans[1][i - 1] ^ 1;
      else
        ans[1][i] = ans[1][i - 1];
    }
    for (int i = 2; i <= h; i++) {
      ans[i][1] = 0;
      for (int j = 2; j <= w; j++) {
        if (mp1[i][j - 1] == 0)
          ans[i][j] = ans[i][j - 1] ^ 1;
        else
          ans[i][j] = ans[i][j - 1];
      }
      int tmp = 0, tot = 0;
      for (int j = 1; j <= w; j++) {
        if ((ans[i][j] == ans[i - 1][j]) == mp2[i - 1][j]) tmp++;
        tot++;
      }
      if (tmp * 2 < tot) {
        for (int j = 1; j <= w; j++) ans[i][j] ^= 1;
      }
    }
  } else {
    ans[1][1] = 0;
    for (int i = 2; i <= h; i++) {
      if (mp2[i - 1][1] == 0)
        ans[i][1] = ans[i - 1][1] ^ 1;
      else
        ans[i][1] = ans[i - 1][1];
    }
    for (int i = 2; i <= w; i++) {
      ans[1][i] = 0;
      for (int j = 2; j <= h; j++) {
        if (mp2[j - 1][i] == 0)
          ans[j][i] = ans[j - 1][i] ^ 1;
        else
          ans[j][i] = ans[j - 1][i];
      }
      int tmp = 0, tot = 0;
      for (int j = 1; j <= h; j++) {
        if ((ans[j][i] == ans[j][i - 1]) == mp1[j][i - 1]) tmp++;
        tot++;
      }
      if (tmp * 2 < tot) {
        for (int j = 1; j <= h; j++) ans[j][i] ^= 1;
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << 1 + ans[i][j] << ' ';
    }
    puts("");
  }
}
