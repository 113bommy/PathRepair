#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  cin >> s1;
  char s[4];
  int n = s1.length();
  int kr = 0;
  int kb = 0;
  int ky = 0;
  int kg = 0;
  for (int i = 0; i <= n - 4; i += 4) {
    int fr = 0;
    int fb = 0;
    int fy = 0;
    int fg = 0;
    for (int j = i; j < i + 4; j++) {
      if (s1[j] == 'R') {
        fr = 1;
        s[j - i] = 'R';
      } else if (s1[j] == 'B') {
        fb = 1;
        s[j - i] = 'B';
      } else if (s1[j] == 'Y') {
        fy = 1;
        s[j - i] = 'Y';
      } else if (s1[j] == 'G') {
        fg = 1;
        s[j - i] = 'G';
      }
    }
    if (fr == 0) {
      kr++;
    }
    if (fb == 0) {
      kb++;
    }
    if (fy == 0) {
      ky++;
    }
    if (fg == 0) {
      kg++;
    }
  }
  int x = n % 4;
  if (x == 1) {
    for (int i = (n - x); i < n; i++) {
      if (s1[i] == '!') {
        if (s[(i - (n - x))] == 'R') {
          kr++;
        } else if (s[(i - (n - x))] == 'G') {
          kg++;
        } else if (s[(i - (n - x))] == 'B') {
          kb++;
        } else if (s[(i - (n - x))] == 'Y') {
          ky++;
        }
      } else
        continue;
    }
  } else if (x == 2) {
    for (int i = (n - x); i < n; i++) {
      if (s1[i] == '!') {
        if (s[(i - (n - x))] == 'R') {
          kr++;
        } else if (s[(i - (n - x))] == 'G') {
          kg++;
        } else if (s[(i - (n - x))] == 'B') {
          kb++;
        } else if (s[(i - (n - x))] == 'Y') {
          ky++;
        }
      } else
        continue;
    }
  } else if (x == 3) {
    for (int i = (n - x); i < n; i++) {
      if (s1[i] == '!') {
        if (s[(i - (n - x))] == 'R') {
          kr++;
        } else if (s[(i - (n - x))] == 'G') {
          kg++;
        } else if (s[(i - (n - x))] == 'B') {
          kb++;
        } else if (s[(i - (n - x))] == 'Y') {
          ky++;
        }
      } else
        continue;
    }
  }
  cout << kr << " " << kb << " " << ky << " " << kg << endl;
}
