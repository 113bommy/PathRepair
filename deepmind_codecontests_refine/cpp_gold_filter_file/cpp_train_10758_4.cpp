#include <bits/stdc++.h>
using namespace std;
const int N = 440000;
const int MOD = 123456789;
int Fo[N], Ba[N], pw[N];
char s[N];
int getFo(int lo, int hi) { return Fo[hi] - Fo[lo - 1]; }
int getBa(int lo, int hi) { return Ba[hi] - Ba[lo - 1]; }
int main() {
  int d;
  scanf("%d", &d);
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 27;
  bool free = false;
  for (int i = 1; i <= n; i++) {
    int from = (free ? 0 : s[i] - 'a'), st = from;
    if (i == n && !free) from++;
    for (; from < 26; from++) {
      Fo[i] = Fo[i - 1] + pw[n - i] * from;
      Ba[i] = Ba[i - 1] + pw[i - 1] * from;
      if (i >= d) {
        if (pw[i - d] * getFo(i - d + 1, i) == pw[n - i] * getBa(i - d + 1, i))
          continue;
      }
      if (i > d) {
        if (pw[i - d - 1] * getFo(i - d, i) == pw[n - i] * getBa(i - d, i))
          continue;
      }
      s[i] = from + 'a';
      break;
    }
    if (from < 26) {
      if (from != st) free = true;
      continue;
    }
    i--;
    while (i) {
      from = s[i] - 'a' + 1;
      for (; from < 26; from++) {
        Fo[i] = Fo[i - 1] + pw[n - i] * from;
        Ba[i] = Ba[i - 1] + pw[i - 1] * from;
        if (i >= d) {
          if (pw[i - d] * getFo(i - d + 1, i) ==
              pw[n - i] * getBa(i - d + 1, i))
            continue;
        }
        if (i > d) {
          if (pw[i - d - 1] * getFo(i - d, i) == pw[n - i] * getBa(i - d, i))
            continue;
        }
        s[i] = from + 'a';
        break;
      }
      if (from < 26) {
        free = true;
        break;
      }
      i--;
    }
    if (!i) return puts("Impossible"), 0;
  }
  return puts(s + 1), 0;
}
