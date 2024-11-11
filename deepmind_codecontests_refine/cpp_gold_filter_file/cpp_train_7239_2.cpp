#include <bits/stdc++.h>
using namespace std;
int best = -1;
int price = 0;
int n;
int a[10][10];
int h[10][10];
int l[10][10];
int cur[10];
void gen(int i, int j) {
  if (j >= n) {
    if (i >= n - 1) {
      best = max(best, price);
      return;
    }
    if (cur[i] != 0) return;
    gen(i + 1, i + 2);
    return;
  }
  for (int k = l[i][j]; k <= h[i][j]; k++) {
    if (k > cur[i]) continue;
    cur[i] -= k;
    cur[j] += k;
    int val = k * k;
    if (k > 0) val += a[i][j];
    price += val;
    gen(i, j + 1);
    price -= val;
    cur[i] += k;
    cur[j] -= k;
  }
}
void push(int x) {
  for (int i = 0; i < 10; i++) cur[i] = 0;
  cur[0] = x;
  price = 0;
  gen(0, 1);
  if (best != -1) {
    cout << x << " " << best << endl;
    exit(0);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    int l1, l2;
    cin >> l1 >> l2;
    l1--;
    l2--;
    cin >> l[l1][l2] >> h[l1][l2] >> a[l1][l2];
    l[l2][l1] = l[l1][l2];
    h[l2][l1] = h[l1][l2];
    a[l2][l1] = a[l1][l2];
  }
  for (int i = 0; i <= 30; i++) push(i);
  cout << -1 << " " << -1 << endl;
  return 0;
}
