#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 1e5 + 5;
pair<int, int> s[maxn];
int a[maxn], b[maxn];
int MAIN() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i].first);
    s[i].second = i;
  }
  sort(s, s + n);
  int c = (n + 2) / 3;
  for (int i = 0; i < c; ++i) {
    a[s[i].second] = i;
    b[s[i].second] = s[i].first - i;
  }
  for (int i = 0; i + c < n; ++i) {
    int j = i + c;
    b[s[j].second] = j;
    a[s[j].second] = s[j].first - j;
  }
  for (int i = 0; i + 2 * c < n; ++i) {
    int j = i + 2 * c;
    b[s[j].second] = n - 1 - j;
    a[s[j].second] = s[j].first - (n - 1 - j);
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
  for (int i = 0; i < n; ++i) {
    printf("%d ", b[i]);
  }
  puts("");
  return 0;
}
int main() { return MAIN(); }
