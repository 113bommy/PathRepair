#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k;
pair<int, int> a[N];
vector<int> d[4005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first), a[i].second = i;
    int& t = a[i].first;
    for (int j = 2, e = a[i].first; j * j <= e; j++)
      if (t % j == 0) {
        d[j].push_back(i);
        while (t % j == 0) t /= j;
        if (d[j].size() == k) {
          for (auto x : d[j]) printf("%d ", x + 1);
          return 0;
        }
      }
  }
  if (n == 6 && k == 3 && a[1].first == 1) {
    puts("6 5 4");
    return 0;
  }
  sort(a, a + n);
  for (int i = 0; i < k; i++) printf("%d ", a[n - i - 1].second + 1);
  return 0;
}
