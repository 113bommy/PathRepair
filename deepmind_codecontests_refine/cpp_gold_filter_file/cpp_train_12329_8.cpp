#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100];
  int n, _size;
  long long ans = 0;
  stack<char> st;
  while (scanf("%d", &n) == 1) {
    scanf("%s", s);
    long long pre = 0;
    long long ans = 0;
    for (__typeof(n) i = 0; i < n; i++) {
      if (s[i] == 'B') ans = ans + pre + 1;
      pre = (pre << 1) + 1;
    }
    printf("%I64d\n", ans);
  }
}
