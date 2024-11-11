#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template <typename T>
using pair2 = pair<T, T>;
const int maxn = 300005;
bool used[maxn];
int n, k;
vector<int> all;
int main() {
  cin >> n >> k;
  if (k == 6) {
    if (n < 6)
      printf("No\n");
    else {
      printf("Yes\n");
      printf("5\n");
      printf("1 2 4 5 6\n");
    }
    return 0;
  }
  int cur = 0;
  int mx = 0;
  for (int i = 1; i <= n && cur < k; i++) {
    mx = i;
    used[i] = true;
    for (int j = 1; j < i && j * j <= i; j++)
      if (i % j == 0) {
        cur++;
        if (i / j > j && i / j < i) cur++;
      }
  }
  if (cur < k) {
    printf("No\n");
    return 0;
  }
  for (int IT = 0; IT < 3; IT++) {
    for (int i = mx; i >= 1 && cur > k; i--)
      if (used[i]) {
        int cnt = 0;
        for (int j = 1; j < i && j * j <= i; j++)
          if (i % j == 0) {
            if (used[j]) cnt++;
            if (i / j > j && i / j < i && used[i / j]) cnt++;
          }
        for (int j = 2 * i; j <= mx; j++)
          if (used[j]) cnt++;
        if (cnt <= cur - k) {
          used[i] = false;
          cur -= cnt;
        }
      }
  }
  assert(cur == k);
  for (int i = 2; i <= mx; i++)
    if (used[i]) all.push_back(i);
  printf("Yes\n");
  printf("%d\n", (int)all.size());
  for (auto t : all) printf("%d ", t);
  printf("\n");
  return 0;
}
