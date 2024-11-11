#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
vector<int> num;
int main() {
  scanf("%d", &n);
  int t = n, ans = 1, p = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      ans *= i;
      p = max(p, cnt);
      num.push_back(cnt);
    }
  }
  if (n != 1) {
    ans *= n;
    num.push_back(1);
  }
  if (p == 1) {
    printf("%d 0", t);
  } else {
    bool f = 0;
    for (auto it : num) {
      if (it < p) {
        f = 1;
      }
    }
    if (log2(p) != (int)log2(p)) {
      f = 1;
    }
    printf("%d %d", ans, (int)ceil(log2(p)) + f);
  }
}
