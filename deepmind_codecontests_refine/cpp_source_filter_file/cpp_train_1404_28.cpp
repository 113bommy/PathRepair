#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 100001;
int a[N], p[N];
int n, k;
bool cmp(int i, int j) { return a[i] < a[j]; }
int main(void) {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    p[i] = i;
  }
  sort(p, p + n, cmp);
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[p[i]] <= k) {
      v.push_back(p[i]);
      sum += p[a[i]];
    }
  }
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf("%d ", v[i] + 1);
  }
  return 0;
}
