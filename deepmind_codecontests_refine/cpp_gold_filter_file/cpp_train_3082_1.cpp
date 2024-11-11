#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
char s[1005];
bool v[30];
int pp;
void get(char op) {
  for (int i = a + 1; i <= (a + b); i++) s[i] = op;
  memset(v, 0, sizeof(v));
  for (int i = a + b, j = 0; j < a; j++, i--) v[s[i] - 'a'] = 1;
  for (int i = a + b + 1; i <= (a + a + b); i++) {
    for (int j = 0; j < 26; j++) {
      if (!v[j]) {
        v[j] = 1;
        s[i] = 'a' + j;
        break;
      }
    }
  }
  for (int i = (a + a + b + 1); i <= (a + a + b + b); i++) s[i] = s[a + a + b];
  for (int i = (a + a + b + b + 1); i <= 4 * (a + b); i++)
    s[i] = s[i - a - a - b - b];
}
int main() {
  scanf("%d%d%d%d", &a, &b, &l, &r);
  for (int i = 1; i <= a; i++) s[i] = 'a' + i - 1;
  if (r - l + 1 >= 2 * (a + b)) {
    if (a <= b)
      printf("%d\n", a + 1);
    else
      printf("%d\n", 2 * a - b);
  } else {
    pp = a + a + b + b;
    l = l % pp;
    if (!l) l = pp;
    r = r % pp;
    if (!r) r = pp;
    set<char> st;
    int ans = 1e9;
    int temp;
    for (int i = 0; i < a; i++) {
      get('a' + i);
      st.clear();
      if (l > r) {
        for (int i = l; i <= 2 * (a + b); i++) st.insert(s[i]);
        for (int i = 1; i <= r; i++) st.insert(s[i]);
        temp = st.size();
      } else {
        for (int i = l; i <= r; i++) st.insert(s[i]);
        temp = st.size();
      }
      ans = min(ans, temp);
    }
    printf("%d\n", ans);
  }
}
