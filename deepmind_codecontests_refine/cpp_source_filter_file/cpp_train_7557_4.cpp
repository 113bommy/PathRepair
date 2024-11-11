#include <bits/stdc++.h>
using namespace std;
long long n, k;
char s1[100005], s2[100005], s[100005];
int Fp[30];
int len2;
bool is() {
  int len = strlen(s);
  int flag = 1;
  if (len2 - 1 > len) return false;
  int pos = -1;
  for (int i = 0; i < len2; i++) {
    if (s2[i] == '*') {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    if (len2 != len)
      return false;
    else {
      for (int i = 0; i < len2; i++) {
        if (s2[i] != '?') {
          if (s2[i] != s[i]) {
            flag = 0;
            break;
          }
        } else if (s2[i] == '?') {
          if (Fp[s[i] - 'a'] == 0) {
            flag = 0;
            break;
          }
        }
      }
    }
  }
  if (!flag) return false;
  int st = 0, en = 0;
  for (int i = 0; i < pos; i++) {
    st = i;
    if (s2[i] != '?' && s2[i] != '*') {
      if (s2[i] != s[i]) {
        flag = 0;
        break;
      }
    } else if (s2[i] == '?') {
      if (Fp[s[i] - 'a'] == 0) {
        flag = 0;
        break;
      }
    }
  }
  if (!flag) return false;
  st = pos;
  int i = len - 1, j = len2 - 1;
  while (i >= st) {
    if (i == st) {
      if (j > pos + 1) {
        flag = 0;
        break;
      }
    }
    if (s2[j] == '*') {
      en = j;
      break;
    }
    if (s2[j] != '?') {
      if (s2[j] != s[i]) {
        flag = 0;
        break;
      }
    } else if (s2[j] == '?') {
      if (Fp[s[i] - 'a'] == 0) {
        flag = 0;
        break;
      }
    }
    --j, --i;
  }
  if (!flag) return false;
  en = j;
  for (int i = st; i <= en; i++) {
    if (Fp[s[i] - 'a'] == 1) {
      flag = 0;
      break;
    }
  }
  if (!flag) return false;
  return true;
}
void solve() {
  int len1 = strlen(s1);
  for (int i = 0; i < len1; i++) {
    Fp[s1[i] - 'a'] = 1;
  }
  len2 = strlen(s2);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    if (is()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  solve();
  return 0;
}
