#include <bits/stdc++.h>
using namespace std;
pair<int, int> PII;
const int N = 100005;
int a[N];
int main() {
  int n, len = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    if (a[i] != a[len]) {
      a[++len] = a[i];
    }
  }
  bool f = false;
  for (int i = 0; i < len; i++) {
    if (2 * a[i] > a[i + 1]) {
      f = true;
      break;
    }
  }
  puts(f ? "YES" : "NO");
}
