#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
queue<long long> que[61];
int getDigit(long long num) {
  long long x = 1;
  int res = 0;
  while (x <= num) {
    ++res;
    x <<= 1;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    que[getDigit(x) - 1].push(x);
  }
  vector<int> Ans;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    long long x = 0;
    for (int j = 0; j < 60; j++) {
      if ((s & (1LL << j)) == 0 && !que[j].empty()) {
        x = que[j].front();
        que[j].pop();
        break;
      }
    }
    if (x == 0) {
      printf("No\n");
      return 0;
    }
    s ^= x;
    Ans.push_back(x);
  }
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%lld%c", Ans[i], " \n"[i == n - 1]);
  }
}
