#include <bits/stdc++.h>
int *array;
int seive[1000001];
int prime_prime[1000001];
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int cmp(const void *a, const void *b) {
  int ia = *(int *)a;
  int ib = *(int *)b;
  return array[ia] < array[ib] ? -1 : array[ia] > array[ib];
}
int abs(int n) {
  if (n < 0) return n * (-1);
  return n;
}
void swap(int *a, int *b) {
  *a = (*a) ^ (*b);
  *b = (*a) ^ (*b);
  *a = (*a) ^ (*b);
}
int binSearch(int a[], int x, int l, int r) {
  if (r >= l) {
    int mid = l + ((r - l) >> 1);
    if (a[mid] == x) return mid;
    if (a[mid] > x) {
      return binSearch(a, x, l, mid - 1);
    } else if (a[mid] < x) {
      return binSearch(a, x, mid + 1, r);
    }
  }
  return -1;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void makeSeive() {
  int i;
  seive[1] = 1;
  for (i = 2; i < 1000001; i++) {
    if (seive[i] == 0) {
      long long int temp = (long long int)i * i;
      while (temp <= 1000000) {
        seive[temp] = 1;
        temp += i;
      }
    }
  }
}
int isPrime(int n) {
  int i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void getInput(int a[], int n) {
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
void testCase() {
  long long int i, n, m;
  scanf("%lld%lld", &n, &m);
  if (m - n + 1 < 3) {
    printf("-1");
    return;
  }
  if (m - n + 1 == 3) {
    if (gcd(m, n) != 1) {
      printf("%lld %lld %lld", n, n + 1, m);
    } else {
      printf("-1");
    }
    return;
  }
  if (n % 2 == 0) {
    printf("%lld %lld %lld", n, n + 1, n + 2);
  } else {
    printf("%lld %lld %lld", n + 1, n + 2, n + 3);
  }
}
int main() {
  int t = 1;
  while (t--) {
    testCase();
    printf("\n");
  }
  return 0;
}
