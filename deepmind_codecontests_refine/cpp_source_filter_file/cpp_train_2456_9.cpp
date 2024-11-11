#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Inf = 1e9 + 7;
int n, k;
int a[maxn];
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    int flag = 0;
    long long sum = 0;
    int Min = Inf;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      Min = min(Min, a[i]);
    }
    for (int i = 0; i < Min; i++) {
      if ((a[i] - Min) % k != 0) {
        flag = 1;
        break;
      }
      sum += (a[i] - Min);
    }
    if (flag == 1) {
      printf("-1\n");
    } else {
      cout << sum / (long long)k << endl;
    }
  }
  return 0;
}
