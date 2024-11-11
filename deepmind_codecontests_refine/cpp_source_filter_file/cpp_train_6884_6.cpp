#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char s[500005];
int n;
int leftColon() {
  bool f = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '[') f = 1;
    if (f && s[i] == ':') return i;
  }
  return -1;
}
int rightColon() {
  bool f = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ']') f = 1;
    if (f && s[i] == ':') return i;
  }
  return -1;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int l = leftColon(), r = rightColon();
  if (l < 0 || r < 0 || l == r)
    puts("-1");
  else {
    int ans = 4;
    for (int i = l + 1; i < r; i++)
      if (s[i] == '|') ans++;
    cout << ans << endl;
  }
  return 0;
}
