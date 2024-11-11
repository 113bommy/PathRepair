#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("First\n");
    for (int i = 0; i < 2 * n; ++i) {
      printf("%d ", 1 + (i % n));
    }
    printf("\n");
  } else {
    printf("Second\n");
    fflush(stdout);
    vector<int> mem(n, -1);
    vector<int> other(2 * n);
    for (int i = 1; i <= 2 * n; ++i) {
      int im = i % (2 * n);
      int val = nxt() - 1;
      if (mem[val] == -1) {
        mem[val] = im;
      } else {
        other[im] = mem[val];
        other[mem[val]] = im;
      }
    }
    auto right = [&](int x) { return x >= n; };
    auto swtch = [&](int x) {
      if (right(x)) return x - n;
      return x + n;
    };
    vector<bool> used(n, false);
    vector<int> out(n);
    int sum = 0;
    for (int x = 0; x < n; ++x) {
      if (used[x]) continue;
      for (int y = x; !used[y % n]; y = other[swtch(y)]) {
        used[y % n] = true;
        out[y % n] = right(y);
        sum = (sum + y) % (2 * n);
      }
    }
    if (sum != 0) {
      for (int i = 0; i < n; ++i) out[i] ^= 1;
    }
    printf("%d ", out[0] ? n : 2 * n);
    for (int i = 1; i < n; ++i) {
      printf("%d ", i + n * out[i]);
    }
    printf("\n");
  }
  fflush(stdout);
  int res;
  scanf("%d", &res);
}
