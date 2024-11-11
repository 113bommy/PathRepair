#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 50;
char str[MAXN];
int s[MAXN], a[MAXN], b[MAXN], p[26], sz;
bool used[26];
inline int maxLeft() {
  for (int i = sz - 1; i >= 0; i--)
    if (!used[i]) return i;
  return -1;
}
inline int minLeft() {
  for (int i = 0; i < sz; i++)
    if (!used[i]) return i;
  return -1;
}
void solve() {
  scanf("%d", &sz);
  scanf("%s", str);
  int n = strlen(str);
  for (int i = 0; i < n; i++) s[i] = str[i] - 'a';
  scanf("%s", str);
  for (int i = 0; i < n; i++) a[i] = str[i] - 'a';
  scanf("%s", str);
  for (int i = 0; i < n; i++) b[i] = str[i] - 'a';
  memset(p, -1, sizeof p);
  memset(used, 0, sizeof used);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (p[s[i]] == -1) {
      if (maxLeft() < a[i]) {
        bool flag = false;
        while (!st.empty()) {
          int k = st.top();
          st.pop();
          used[p[s[k]]] = false;
          p[s[k]] = -1;
          if (maxLeft() > a[k]) {
            for (int t = a[k] + 1; t < sz; t++) {
              if (!used[t]) {
                p[s[k]] = t;
                used[t] = true;
                break;
              }
            }
            flag = true;
            break;
          }
        }
        if (flag)
          break;
        else {
          printf("NO\n");
          return;
        }
      } else if (!used[a[i]]) {
        p[s[i]] = a[i];
        used[a[i]] = true;
        st.push(i);
      } else {
        for (int t = a[i] + 1; t < sz; t++) {
          if (!used[t]) {
            p[s[i]] = t;
            used[t] = true;
            break;
          }
        }
        break;
      }
    } else {
      if (p[s[i]] > a[i]) {
        break;
      } else if (p[s[i]] < a[i]) {
        bool flag = false;
        while (!st.empty()) {
          int k = st.top();
          st.pop();
          used[p[s[k]]] = true;
          p[s[k]] = -1;
          if (maxLeft() > a[k]) {
            for (int t = a[k] + 1; t < sz; t++) {
              if (!used[t]) {
                p[s[k]] = t;
                used[t] = true;
                break;
              }
            }
            flag = true;
            break;
          }
        }
        if (flag)
          break;
        else {
          printf("NO\n");
          return;
        }
      }
    }
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < sz; i++)
    if (p[i] != -1) used[p[i]] = true;
  for (int i = 0; i < n; i++) {
    if (p[s[i]] != -1) {
      if (p[s[i]] < b[i]) {
        break;
      } else if (p[s[i]] > b[i]) {
        printf("NO\n");
        return;
      }
    } else {
      p[s[i]] = minLeft();
      used[p[s[i]]] = true;
      if (p[s[i]] < b[i])
        break;
      else if (p[s[i]] > b[i]) {
        printf("NO\n");
        return;
      }
    }
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < sz; i++)
    if (p[i] != -1) used[p[i]] = true;
  for (int i = 0; i < sz; i++) {
    if (p[i] == -1) {
      p[i] = minLeft();
      used[p[i]] = true;
    }
  }
  printf("YES\n");
  for (int i = 0; i < sz; i++) printf("%c", 'a' + p[i]);
  printf("\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
