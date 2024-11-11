#include <bits/stdc++.h>
using namespace std;
__inline bool nextInt(int &val) {
  char ch;
  int sgn = 1;
  while ((ch = getchar()) != EOF) {
    if (ch == '-') sgn = -1;
    if (ch >= '0' && ch <= '9') break;
  }
  if (ch == EOF) return false;
  val = (int)(ch - '0');
  while (true) {
    ch = getchar();
    if (ch >= '0' && ch <= '9') {
      val = 10 * val + (int)(ch - '0');
    } else
      break;
  }
  val *= sgn;
  return true;
}
__inline bool nextString(string &s) {
  char ch;
  while ((ch = getchar()) != EOF) {
    if (ch >= 33 && ch <= 126) break;
  }
  if (ch == EOF) return false;
  s = string(1, ch);
  while (true) {
    ch = getchar();
    if (ch >= 33 && ch <= 126) {
      s = s + string(1, ch);
    } else
      break;
  }
  return true;
}
int n, p1[1000888], p2[1000888];
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 0; i < (n + 1); i++) p1[i] = p2[i] = -1;
  int lbit = (1 << 29);
  while ((n & lbit) == 0) lbit >>= 1;
  long long sum = 0;
  for (int i = n; i >= 0; i--)
    if (p1[i] == -1) {
      while (p1[(2 * lbit - 1) ^ i] != -1 && lbit > 0) lbit >>= 1;
      if (lbit == 0) {
        p1[i] = i;
        continue;
      }
      p1[i] = (2 * lbit - 1) ^ i;
      p1[(2 * lbit - 1) ^ i] = i;
      sum = sum + (i ^ p1[i]);
      sum = sum + ((2 * lbit - 1) ^ i) ^ (p1[(2 * lbit - 1) ^ i]);
    }
  cout << sum << endl;
  for (int i = 0; i < (n + 1); i++) printf("%d ", p1[i]);
  printf("\n");
  return 0;
}
