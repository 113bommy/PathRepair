#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int N;
int arr[300005];
int segf[4 * 300005];
int segb[4 * 300005];
int pow29[300005];
void inv(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return;
  }
  inv((b % a), a, x, y);
  long long z = x;
  long long zz = y;
  x = zz - (b / a) * z;
  y = z;
}
void updatef(int start, int end, int i, int node) {
  if (start > i || end < i) return;
  if (start == end) {
    segf[node] += pow29[start];
    if (segf[node] >= mod) segf[node] -= mod;
    return;
  }
  updatef(start, (start + end) / 2, i, 2 * node);
  updatef((start + end) / 2 + 1, end, i, 2 * node + 1);
  segf[node] = segf[2 * node] + segf[2 * node + 1];
  if (segf[node] >= mod) segf[node] -= mod;
}
void updateb(int start, int end, int i, int node) {
  if (start > i || end < i) return;
  if (start == end) {
    segb[node] += pow29[N - start];
    if (segb[node] >= mod) segb[node] -= mod;
    return;
  }
  updateb(start, (start + end) / 2, i, 2 * node);
  updateb((start + end) / 2 + 1, end, i, 2 * node + 1);
  segb[node] = segb[2 * node] + segb[2 * node + 1];
  if (segb[node] >= mod) segb[node] -= mod;
}
int queryf(int start, int end, int i, int j, int node = 1) {
  if (start > j || end < i) return 0;
  if (start >= i && end <= j) return segf[node];
  return (queryf(start, (start + end) / 2, i, j, 2 * node) +
          queryf((start + end) / 2 + 1, end, i, j, 2 * node + 1)) %
         mod;
}
int queryb(int start, int end, int i, int j, int node = 1) {
  if (start > j || end < i) return 0;
  if (start >= i && end <= j) return segb[node];
  return (queryb(start, (start + end) / 2, i, j, 2 * node) +
          queryb((start + end) / 2 + 1, end, i, j, 2 * node + 1)) %
         mod;
}
int main() {
  pow29[0] = 1;
  for (int g = 1; g <= 300005; g++) pow29[g] = (1LL * 29 * pow29[g - 1]) % mod;
  scanf("%d", &N);
  for (int g = 1; g <= N; g++) {
    scanf("%d", &arr[g]);
    arr[g]--;
  }
  for (int g = 1; g <= N; g++) {
    int t = min(arr[g], N - 1 - arr[g]);
    int first = queryf(0, N - 1, arr[g], arr[g] + t);
    int second = queryb(0, N - 1, arr[g] - t, arr[g]);
    long long R = pow29[arr[g]];
    long long x = 0, y = 0;
    inv(R, mod, x, y);
    x %= mod;
    x += mod;
    x %= mod;
    first = (1LL * first * x) % mod;
    R = pow29[N - arr[g]], x = 0, y = 0;
    inv(R, mod, x, y);
    x %= mod;
    x += mod;
    x %= mod;
    second = (1LL * second * x) % mod;
    if (first != second) {
      if (arr[g] > 0 && arr[g] < N - 1) {
        puts("YES");
        return 0;
      }
    }
    updatef(0, N - 1, arr[g], 1);
    updateb(0, N - 1, arr[g], 1);
  }
  puts("NO");
  return 0;
}
