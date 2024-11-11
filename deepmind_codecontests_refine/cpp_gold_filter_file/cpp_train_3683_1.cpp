#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[100005];
int f1[30000];
int f2[30000];
int f1next, f2next;
int gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;
  if (x == y) return x;
  if (x > y) return gcd(x % y, y);
  return gcd(x, y % x);
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> a[i];
  int totalgcd = 0;
  for (int i = 0; i < N; i++) totalgcd = gcd(totalgcd, a[i] - 1);
  while (totalgcd % 2 == 0) totalgcd /= 2;
  f1next = 0;
  f2next = 0;
  for (int i = 1; i * i <= totalgcd; i++) {
    if (totalgcd % i == 0) {
      f1[f1next++] = i;
      f2[f2next++] = totalgcd / i;
    }
  }
  if (f1[f1next - 1] == f2[f2next - 1]) f2next--;
  int diff;
  long long total = 0;
  for (int i = 0; i < f1next; i++) {
    diff = f1[i];
    while (diff < M) {
      total += M - diff;
      diff *= 2;
    }
  }
  for (int i = 0; i < f2next; i++) {
    diff = f2[i];
    while (diff < M) {
      total += M - diff;
      diff *= 2;
    }
  }
  cout << total << endl;
  return 0;
}
