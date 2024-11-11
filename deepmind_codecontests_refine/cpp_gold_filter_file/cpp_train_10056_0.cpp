#include <bits/stdc++.h>
using namespace std;
const int N = 77;
const int MAX = 55;
long long full[N];
long long notfull[N];
long long extra[N];
long long ende[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long foo;
    scanf("%I64d", &foo);
    bool bar = true;
    int use = 0;
    while (foo > 1) {
      if (foo & 1) {
        bar = false;
      }
      foo >>= 1;
      use++;
    }
    if (bar) {
      full[use]++;
    } else {
      notfull[use]++;
    }
  }
  int low = 1, high = full[0] + 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    int cur = mid;
    for (int i = 0; i < MAX; i++) {
      extra[i] = full[i] - cur;
      long long new_cur = min((long long)cur, full[i + 1]);
      ende[i] = cur - new_cur;
      cur = new_cur;
    }
    bool success = true;
    int open = 0;
    for (int i = MAX - 1; i >= 0; i--) {
      open += ende[i];
      open -= notfull[i];
      open -= extra[i + 1];
      if (open < 0) {
        success = false;
        break;
      }
    }
    open -= extra[0];
    if (open < 0) {
      success = false;
    }
    if (success) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (low > full[0]) {
    puts("-1");
    return 0;
  }
  for (int i = low; i <= full[0]; i++) {
    printf("%d ", i);
  }
  puts("");
  return 0;
}
