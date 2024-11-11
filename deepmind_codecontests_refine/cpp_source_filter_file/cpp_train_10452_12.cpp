#include <bits/stdc++.h>
using namespace std;
struct node {
  int h, d;
  int ind;
};
struct node arr1[100005];
struct node arr2[100005];
int label[100005];
bool cmp1(node val1, node val2) {
  return ((val1.d < val2.d) || (val1.d == val2.d && val1.h < val2.h));
}
bool cmp2(node val1, node val2) {
  return ((val1.h > val2.h) || (val1.h == val2.h && val1.d > val2.d));
}
int main() {
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr1[i].h, &arr1[i].d);
    arr1[i].ind = i + 1;
  }
  sort(arr1, arr1 + n, cmp1);
  for (int i = 0; i < n; i++) {
    label[arr1[i].ind] = i;
    arr2[i] = arr1[i];
  }
  sort(arr1 + p - k, arr1 + n, cmp2);
  int M = 100000000;
  for (int i = 0; i < k; i++) {
    cout << arr1[p - k + i].ind << " ";
    M = min(M, label[arr1[p - k + i].ind]);
  }
  for (int i = 1; i <= p - k; i++) cout << arr2[M - i].ind << " ";
  printf("\n");
  return 0;
}
