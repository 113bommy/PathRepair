#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
int a[MAXN], b[MAXN], choice[MAXN];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  vector<int> vec;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int op = a[i];
    if (choice[op] == 0) {
      cnt++;
      choice[op] = b[i];
    } else if (choice[op] < b[i]) {
      vec.push_back(choice[op]);
      choice[op] = b[i];
    } else {
      vec.push_back(b[i]);
    }
  }
  long long ans = 0;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < k - cnt; i++) ans += vec[i];
  printf("%lld\n", ans);
}
