#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
int tool[26];
char K[100];
int F(int L, int R) {
  memset(tool, 0, sizeof(tool));
  int cnt = 0;
  for (int i = L; i <= R; i++) {
    if (tool[K[i] - 'a'] == 0) {
      tool[K[i] - 'a'] = 1;
      cnt++;
    }
  }
  return cnt;
}
int main() {
  cin >> a >> b >> l >> r;
  l--;
  r--;
  if (r - l + 1 >= (a + b) * 2) {
    l = 0;
    r = (a + b) * 2 - 1;
  } else {
    l %= (a + b) * 2;
    r %= (a + b) * 2;
    if (r < l) r += (a + b) * 2;
  }
  int i;
  memset(tool, 0, sizeof(tool));
  int ans;
  if (a > b + 1) {
    for (i = 0; i < b; i++) {
      K[i + a + b] = K[i] = 'a' + i;
    }
    for (i = b; i < a; i++) {
      K[i] = 'a' + i;
      K[i + a + b] = K[i] + a - b;
    }
    for (i = a; i < a + b; i++) {
      K[i] = K[b + 1];
      K[i + a + b] = K[a + b * 2 + 1];
    }
    for (i = 0; i < a * 2 + b * 2; i++) {
      K[i + a * 2 + b * 2] = K[i];
    }
    ans = F(l, r);
    for (i = a; i < a + b; i++) {
      K[i] = K[a - 2];
      K[i + a + b] = K[a * 2 + b - 2];
    }
    for (i = 0; i < a * 2 + b * 2; i++) {
      K[i + a * 2 + b * 2] = K[i];
    }
    ans = min(ans, F(l, r));
  } else {
    for (i = 0; i < a; i++) {
      K[i] = K[i + a + b] = 'a' + i;
    }
    for (i = a; i < a + b; i++) K[i] = K[i - 1];
    K[a * 2 + b - 1]++;
    for (i = a + a + b; i < (a + b) * 2; i++) K[i] = K[i - 1];
    for (i = 0; i < a * 2 + b * 2; i++) {
      K[i + a * 2 + b * 2] = K[i];
    }
    ans = F(l, r);
  }
  cout << ans;
  return 0;
}
