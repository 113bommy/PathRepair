#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
const int MAXN = 100010;
char src[MAXN];
stack<int> s;
int sum[MAXN], N;
int main() {
  while (scanf("%s", src + 1) != EOF) {
    N = strlen(src + 1);
    sum[0] = 0;
    int l = -1, r = -1, ans = 0;
    while (!s.empty()) s.pop();
    for (int i = 1; i <= N; i++) {
      sum[i] = sum[i - 1] + (src[i] == '[');
      if (s.empty()) {
        s.push(i);
      } else {
        char tmp = src[s.top()];
        if ((tmp == '(' && src[i] == ')') || (tmp == '[' && src[i] == ']')) {
          s.pop();
          if (s.empty() && sum[i] - sum[0] > ans) {
            ans = sum[i] - sum[0];
            l = 1;
            r = i;
          } else if (!s.empty() && sum[i] - sum[s.top()] > ans) {
            ans = sum[i] - sum[s.top()];
            l = s.top() + 1;
            r = i;
          }
        } else
          s.push(i);
      }
    }
    printf("%d\n", ans);
    if (ans) {
      for (int i = l; i <= r; i++) printf("%c", src[i]);
      puts("");
    }
  }
  return 0;
}
