#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
vector<bitset<100000> > a;
vector<int> b;
long long num[100000];
int n, cnt[62];
int important[62];
int ans[100000] = {0};
void add(bitset<100000> A, int B) {
  int m = a.size();
  for (int i = 0; i < m; i++) {
    if (A[important[i]]) {
      A ^= a[i];
      B ^= b[i];
    }
  }
  int idx = -1;
  for (int i = 0; i < n; i++)
    if (A[i]) {
      idx = i;
      break;
    }
  if (idx == -1) return;
  important[m] = idx;
  for (int i = 0; i < m; i++) {
    if (a[i][idx]) {
      a[i] ^= A;
      b[i] ^= B;
    }
  }
  a.push_back(A);
  b.push_back(B);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &num[i]);
    for (int j = 0; j < 62; j++) cnt[j] += (num[i] >> j) & 1;
  }
  for (int i = 61; i >= 0; i--) {
    if (cnt[i] && (cnt[i] & 1)) {
      bitset<100000> t;
      t.reset();
      for (int j = 0; j < n; j++) t[j] = (num[j] >> i) & 1;
      add(t, 0);
    }
  }
  for (int i = 61; i >= 0; i--) {
    if (cnt[i] && !(cnt[i] & 1)) {
      bitset<100000> t;
      t.reset();
      for (int j = 0; j < n; j++) t[j] = (num[j] >> i) & 1;
      add(t, 1);
    }
  }
  for (int i = 0; i < a.size(); i++) {
    ans[important[i]] = b[i];
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", 2 - ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
