#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int a[10], m[maxn];
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  memset(m, 0, sizeof(m));
  for (int i = 0; s[i]; i++) {
    if (!m[s[i] - 'A']) cnt++;
    m[s[i] - 'A']++;
  }
  if (cnt == 1) {
    cout << 1;
    return 0;
  }
  if (cnt == 2) {
    int j = 0;
    for (int i = 0; i < cnt; i++)
      for (; j < 26; j++)
        if (m[j]) {
          a[i] = m[j];
          j++;
          break;
        }
    if (a[0] == 1 || a[0] == 5) {
      cout << 1;
      return 0;
    }
    if (a[0] == 2 || a[0] == 4) {
      cout << 2;
      return 0;
    }
    if (a[0] == 3) {
      cout << 2;
      return 0;
    }
  }
  if (cnt == 3) {
    int j = 0;
    for (int i = 0; i < cnt; i++)
      for (; j < 26; j++)
        if (m[j]) {
          a[i] = m[j];
          j++;
          break;
        }
    if (a[2] == 4 || a[0] == 4 || a[1] == 4) {
      cout << 2;
      return 0;
    }
    if (a[0] == 1 && a[1] == 2 || a[0] == 1 && a[2] == 2 ||
        a[1] == 1 && a[2] == 2) {
      cout << 3;
      return 0;
    }
    if (a[0] + a[1] + a[2] == 6) {
      cout << 6;
      return 0;
    }
  }
  if (cnt == 4) {
    int j = 0;
    for (int i = 0; i < cnt; i++)
      for (; j < 26; j++)
        if (m[j]) {
          a[i] = m[j];
          j++;
          break;
        }
    if (a[0] == 3 || a[1] == 3 || a[2] == 3 || a[3] == 3) {
      cout << 5;
      return 0;
    }
    if (a[0] == 2 || a[1] == 2 || a[2] == 2 || a[3] == 2) {
      cout << 8;
      return 0;
    }
    return 0;
  }
  if (cnt == 5) {
    cout << 15;
    return 0;
  }
  if (cnt == 6) {
    cout << 30;
    return 0;
  }
  return 0;
}
