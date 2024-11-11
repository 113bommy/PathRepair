#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
char s[maxn], t[maxn];
int nxt[maxn];
void getNxt(int m) {
  int i = 1, j = 0;
  nxt[0] = 0;
  while (i < m) {
    if (t[i] == t[j])
      nxt[i++] = ++j;
    else if (!j)
      i++;
    else
      j = nxt[j - 1];
  }
}
int main() {
  scanf("%s%s", s, t);
  int len1 = strlen(s), len2 = strlen(t);
  int len1_0 = 0, len1_1 = 0, len2_0 = 0, len2_1 = 0;
  for (int i = 0; i < len1; i++) {
    int k = s[i] - '0';
    if (k == 0)
      len1_0++;
    else
      len1_1++;
  }
  for (int i = 0; i < len2; i++) {
    int k = t[i] - '0';
    if (k == 0)
      len2_0++;
    else
      len2_1++;
  }
  getNxt(len2);
  int k = nxt[len2 - 1];
  if (len1 < len2) {
    for (int i = 0; i < len1; i++) cout << s[i];
  } else if (len1 == len2) {
    if (len1_0 != len2_0 || len1_1 != len2_1) {
      for (int i = 0; i < len1; i++) cout << s[i];
    } else {
      for (int i = 0; i < len1; i++) cout << t[i];
    }
  } else {
    if (len2_0 == 0) {
      for (int i = 1; i <= len1_1; i++) {
        cout << "1";
      }
      for (int i = 1; i <= len1_0; i++) {
        cout << "0";
      }
      return 0;
    } else if (len2_1 == 0) {
      for (int i = 1; i <= len1_1; i++) {
        cout << "1";
      }
      for (int i = 1; i <= len1_0; i++) {
        cout << "0";
      }
      return 0;
    }
    if (len1_0 < len2_0 || len1_1 < len2_1) {
      for (int i = 0; i < len1; i++) cout << s[i];
    } else {
      if (k == 0) {
        int p = min(len1_0 / len2_0, len1_1 / len2_1);
        for (int j = 1; j <= p; j++) {
          for (int i = 0; i < len2; i++) {
            cout << t[i];
          }
        }
        len1_0 = len1_0 - len2_0 * p;
        len1_1 = len1_1 - len2_1 * p;
        for (int i = 1; i <= len1_0; i++) {
          cout << "0";
        }
        for (int i = 1; i <= len1_1; i++) {
          cout << "1";
        }
      } else {
        int f0 = 0, f1 = 0;
        for (int i = k; i < len2; i++) {
          int p = t[i] - '0';
          if (p == 0)
            f0++;
          else
            f1++;
        }
        for (int i = 0; i < len2; i++) {
          cout << t[i];
        }
        len1_0 -= len2_0;
        len1_1 -= len2_1;
        int p = min(len1_0 / f0, len1_1 / f1);
        len1_0 = len1_0 - f0 * p;
        len1_1 = len1_1 - f1 * p;
        for (int j = 1; j <= p; j++) {
          for (int i = k; i < len2; i++) {
            cout << t[i];
          }
        }
        for (int i = 1; i <= len1_0; i++) {
          cout << "0";
        }
        for (int i = 1; i <= len1_1; i++) {
          cout << "1";
        }
      }
    }
  }
  return 0;
}
