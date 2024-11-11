#include <bits/stdc++.h>
using namespace std;
char s[200001];
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int ans = 0;
  int l = 0, r = n - 1;
  while (l < n && s[l] == '<') ans++, l++;
  while (r > 0 && s[r] == '>') ans++, r--;
  printf("%d\n", ans);
}
