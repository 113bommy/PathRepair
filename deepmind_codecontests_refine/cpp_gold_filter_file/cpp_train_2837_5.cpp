#include <bits/stdc++.h>
using namespace std;
int cmp123(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int cmp321(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int cmp2d(const void* a, const void* b) {
  int* arr1 = (int*)a;
  int* arr2 = (int*)b;
  int diff = arr1[0] - arr2[0];
  if (diff) return diff;
  return (arr1[1] - arr2[1]);
}
void scan_and_sort(int table[], int n, int sort) {
  for (int i = 0; i < n; i++) scanf("%d", &table[i]);
  if (sort == 123) qsort(table, n, sizeof(int), cmp123);
  if (sort == 321) qsort(table, n, sizeof(int), cmp321);
  return;
}
int gcd(int a, int b) {
  int tmp;
  while (a % b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return b;
}
int isPrime(int n) {
  int m = sqrt(n);
  for (int i = 2; i <= m; i++)
    if (n % i == 0) return 0;
  return 1;
}
typedef struct node {
  int num;
  struct node* next;
} Node;
int main(int argc, char const* argv[]) {
  int t;
  scanf("%d", &t);
  int n, m, tmp;
  while (t--) {
    scanf("%d %d", &n, &m);
    int row[50] = {0}, col[50] = {0}, r = 0, c = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf("%d", &tmp);
        if (tmp) {
          row[i] = 1;
          col[j] = 1;
        }
      }
    for (int i = 0; i < n; i++)
      if (!row[i]) r++;
    for (int i = 0; i < m; i++)
      if (!col[i]) c++;
    (((r) < (c) ? (r) : (c)) % 2) ? printf("Ashish\n") : printf("Vivek\n");
  }
  return 0;
}
