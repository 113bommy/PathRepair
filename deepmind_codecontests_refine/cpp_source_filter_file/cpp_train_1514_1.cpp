#include <bits/stdc++.h>
using namespace std;
int ans;
char c;
int main() {
  c = getchar();
  for (int i = 0; i < 6; i++) {
    c = getchar();
    if (c == '1')
      ans += 10;
    else
      ans += c - '0';
  }
  printf("%d", ans);
  return 0;
}
