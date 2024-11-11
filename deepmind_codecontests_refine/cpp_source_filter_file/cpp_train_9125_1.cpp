#include <bits/stdc++.h>
using namespace std;
int n, q, pos;
int arr[(int)2e5 + 100];
long long acc[(int)2e5 + 100];
long long rec;
void add(int pos, int d) {
  while (pos <= n) {
    acc[pos] += d;
    pos += pos & -pos;
  }
}
int find(long long sum) {
  rec = 0;
  int b = 0;
  for (int i = 20; i--;) {
    int t = b ^ (1 << i);
    if (t > n) continue;
    if (rec + acc[t] <= sum) {
      b = t;
      rec += acc[t];
    }
  }
  return b;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    add(i, arr[i]);
  }
  for (; q--; printf("%d\n", pos > n ? -1 : pos)) {
    int i, j;
    scanf("%d%d", &i, &j);
    add(i, j - arr[i]);
    arr[i] = j;
    long long tmp = 0, tsum = 0;
    while (1) {
      pos = find(tsum);
      pos++;
      if (pos > n || rec == arr[pos]) break;
      tsum = 2 * (rec + arr[pos]) - 1;
    }
  }
  return 0;
}
