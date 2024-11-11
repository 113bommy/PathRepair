#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int posMod(int a, int m) { return ((a % m) + m) % m; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int arr[200001], n;
int upper_bound(int x) {
  int low = 0, high = n - 1, mid = 0, ind = n;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] > x) {
      high = mid - 1;
      ind = mid;
    } else
      low = mid + 1;
  }
  return ind;
}
int main() {
  int m, x;
  scanf("%d %d", &n, &m);
  for (int i = (0); i <= (n - 1); i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  for (int i = (0); i <= (m - 1); i++) {
    scanf("%d", &x);
    int ans = upper_bound(x);
    printf("%d ", ans);
  }
  return 0;
}
