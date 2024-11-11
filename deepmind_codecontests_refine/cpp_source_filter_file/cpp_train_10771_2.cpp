#include <bits/stdc++.h>
using namespace std;
int bit[200050];
int n;
int lowbit(int x) { return x & (-x); }
int sum(int x) {
  int sum = 0;
  while (x > 0) {
    sum += bit[x];
    x -= lowbit(x);
  }
  return sum;
}
void push(int pos, int num) {
  while (pos <= n) {
    bit[pos] += num;
    pos += lowbit(pos);
  }
}
int kth(int k) {
  int num = 0;
  int x = 0;
  for (int i = 1 << 18; i > 0; i >>= 1) {
    num += i;
    if (num >= n || x + bit[num] >= k)
      num -= i;
    else
      x += bit[num];
  }
  return num + 1;
}
int main() {
  scanf("%d", &n);
  int a[200050];
  int x;
  memset((bit), (0), sizeof((bit)));
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    push(x + 1, 1);
    a[i] += x - sum(x);
  }
  memset((bit), (0), sizeof((bit)));
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    push(x + 1, 1);
    a[i] += x - sum(x);
  }
  for (int i = n - 1; i > 0; i--) {
    if (a[i] >= n - i) {
      a[i - 1]++;
      a[i] -= n - i;
    }
  }
  if (a[0] >= n) a[0] -= n;
  for (int i = 0; i < n; i++) {
    int num = kth(a[i] + 1);
    printf("%d ", num - 1);
    push(num, -1);
  }
  return 0;
}
