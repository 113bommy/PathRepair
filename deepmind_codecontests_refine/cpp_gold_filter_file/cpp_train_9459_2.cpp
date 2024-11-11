#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[100010];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int foo;
    scanf("%d", &foo);
    a[i] = make_pair(foo, i);
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].second % 2 != i % 2) {
      ++ans;
    }
  }
  printf("%d\n", ans / 2);
  return 0;
}