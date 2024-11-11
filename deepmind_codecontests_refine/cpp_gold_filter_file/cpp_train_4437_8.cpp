#include <bits/stdc++.h>
using namespace std;
void printarray(long long int arr[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    printf("%I64d ", arr[i]);
  }
  printf("\n");
}
int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> ap[n], bp[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ap[i].first);
    ap[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &bp[i].first);
    bp[i].second = i;
  }
  sort(ap, ap + n);
  sort(bp, bp + n);
  int ans[n];
  for (int i = 0; i < n; i++) {
    ans[bp[i].second] = ap[n - 1 - i].first;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
