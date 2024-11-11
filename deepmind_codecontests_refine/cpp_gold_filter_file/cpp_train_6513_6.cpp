#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
int n, a, b, k, c[N];
char s[N];
vector<int> v;
int main() {
  scanf("%d %d %d %d %s", &n, &a, &b, &k, s);
  memset(c, 0, sizeof c);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int f = max(0, i - b + 1);
      c[f]++;
      c[i + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
  }
  for (int i = 0; i < n;) {
    if (c[i] > 0) {
      i++;
      continue;
    }
    int j = i;
    while (j < n && c[j] == 0) {
      j++;
    }
    for (int p = i; p < j && p + b <= n; p += b) {
      v.push_back(p + b);
    }
    i = j;
  }
  printf("%d\n", (int)v.size() - a + 1);
  while (v.size() >= a) {
    printf("%d ", v.back());
    v.pop_back();
  }
  puts("");
  return 0;
}
