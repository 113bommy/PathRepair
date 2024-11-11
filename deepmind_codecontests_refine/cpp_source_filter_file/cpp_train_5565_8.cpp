#include <bits/stdc++.h>
using namespace std;
long long readInt();
void printInt(long long x);
long long BIT[1000002], nums[1000001];
int lft[1000001], rght[1000001];
int n;
void UPDATE(int i, int val) {
  for (i; i <= n; i |= i + 1) BIT[i] += val;
}
long long SUM(int n) {
  long long x = 0;
  while (n >= 0) {
    x += BIT[n];
    n &= (n + 1);
    n--;
  }
  return x;
}
void SOLVE() {
  memset(BIT, 0, sizeof(BIT));
  cin >> n;
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    freq[nums[i]]++;
    lft[i] = freq[nums[i]];
  }
  freq.clear();
  for (int i = n - 1; i >= 0; i--) {
    freq[nums[i]]++;
    rght[i] = freq[nums[i]];
    UPDATE(rght[i], 1);
  }
  long long ctr = 0;
  for (int i = 0; i < n; i++) {
    UPDATE(rght[i], -1);
    ctr += SUM(lft[i] - 1);
  }
  cout << ctr << endl;
}
int main() {
  double _time = clock();
  if (7) freopen("input.txt", "r", stdin);
  SOLVE();
  if (7) printf("Exec time: %0.6f sec\n", (clock() - _time) / CLOCKS_PER_SEC);
  return 0;
}
long long readInt() {
  register int c = getchar();
  long long x = 0, neg = 0;
  for (; ((c < '0' || c > '9') && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c - '0');
  return (neg) ? -x : x;
}
void printInt(long long x) {
  char pri[30];
  int i = 0;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  do {
    pri[i++] = (x % 10) + '0';
    x /= 10;
  } while (x != 0);
  for (int j = (i - 1); j > (0 - 1); j -= 1) putchar(pri[j]);
}
