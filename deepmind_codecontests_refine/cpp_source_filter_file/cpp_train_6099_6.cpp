#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int id[200010], n, m;
bool check(int x) {
  int cur = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (id[i] <= x) continue;
    if (s2[cur] == s1[i]) cur++;
    if (cur == s2.length()) return 1;
  }
  return 0;
}
int main() {
  cin >> s1 >> s2;
  int i, x;
  for (i = 1; i <= s1.length(); i++) {
    scanf("%d", &x);
    id[x - 1] = i;
  }
  int l = 1, r = s1.length(), mid;
  while (l + 1 != r) {
    mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d", l);
}
