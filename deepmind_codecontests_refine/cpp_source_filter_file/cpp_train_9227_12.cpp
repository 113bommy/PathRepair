#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int n, x1, x2;
pair<int, int> a[N];
void go(int start1, bool sw) {
  int k1 = (x1 + a[start1].first - 1) / a[start1].first;
  int start2 = start1 + k1;
  if (start2 >= n) {
    return;
  }
  if ((long long)(n - start2) * a[start2].first < x2) {
    return;
  }
  vector<int> v1, v2;
  for (int i = start1; i < start2; i++) {
    v1.push_back(a[i].second);
  }
  int k2 = 0;
  for (int i = start2; i < n; i++) {
    k2++;
    v2.push_back(a[i].second);
  }
  if (sw) {
    swap(k1, k2);
    swap(v1, v2);
  }
  printf("Yes\n");
  printf("%d %d\n", k1, k2);
  for (int x : v1) {
    printf("%d ", x + 1);
  }
  printf("\n");
  for (int x : v2) {
    printf("%d ", x + 2);
  }
  printf("\n");
  exit(0);
}
int main() {
  scanf("%d%d%d", &n, &x1, &x2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    go(i, false);
    swap(x1, x2);
    go(i, true);
    swap(x1, x2);
  }
  puts("No");
  return 0;
}
