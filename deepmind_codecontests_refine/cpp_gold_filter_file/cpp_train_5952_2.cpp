#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int q, n, arr[N], f[N];
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", arr + i);
      ++f[arr[i]];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (f[arr[i]]) {
        v.push_back(f[arr[i]]);
        f[arr[i]] = 0;
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int sum = 0, prev = 1e9;
    for (int i : v) {
      if (prev > i)
        prev = i;
      else
        prev = prev - 1;
      sum += max(prev, 0);
    }
    printf("%d\n", sum);
  }
  return 0;
}
