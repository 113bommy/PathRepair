#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, k;
int st[N], mn[N], mx[N];
char s[N];
int val[256];
int main() {
  val['L'] = -1;
  val['W'] = 1;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int top = 0, score = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      mx[top] = mn[top] = score;
      st[top++] = i;
    } else {
      score += val[s[i]];
      if (top > 0) {
        mn[top - 1] = min(mn[top - 1], score);
        mx[top - 1] = max(mx[top - 1], score);
      }
      if (score == k) {
        if (top == 0 || mn[top - 1] == -k + 1) return printf("NO\n"), 0;
        --top;
        s[st[top]] = 'L';
        mx[top] -= 1;
        mn[top] -= 1;
        if (top > 0) {
          mn[top - 1] = min(mn[top - 1], mn[top]);
          mx[top - 1] = max(mx[top - 1], mx[top]);
        }
        score -= 1;
      } else if (score == -k) {
        if (top == 0 || mx[top - 1] == k - 1) return printf("NO\n"), 0;
        --top;
        s[st[top]] = 'W';
        mx[top] += 1;
        mn[top] += 1;
        if (top > 0) {
          mn[top - 1] = min(mn[top - 1], mn[top]);
          mx[top - 1] = max(mx[top - 1], mx[top]);
        }
        score += 1;
      }
    }
  }
  if (top >= k - score) {
    bool ok = true;
    for (int i = 0; ok && i < k - score; ++i) {
      if (mx[top - i - 1] > score + i) ok = false;
      s[st[top - i - 1]] = 'W';
    }
    if (ok) {
      for (int i = top - k + score - 1; i >= 0; --i) s[st[i]] = 'D';
      return printf("%s\n", s), 0;
    }
  }
  if (top >= score - (-k)) {
    bool ok = true;
    for (int i = 0; ok && i < score - (-k); ++i) {
      if (mn[top - i - 1] < score - i) ok = false;
      s[st[top - i - 1]] = 'L';
    }
    if (ok) {
      for (int i = top - score - k - 1; i >= 0; --i) s[st[i]] = 'D';
      return printf("%s\n", s), 0;
    }
  }
  printf("NO\n");
}
