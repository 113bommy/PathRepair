#include <bits/stdc++.h>
using namespace std;
const double clf = 1e-8;
const int MMAX = 0x7fffffff;
const int INF = 0xfffffff;
const int mod = 1e9 + 7;
int A[100100];
int BIT[100100];
int MAX_N, m;
int lowbit(int x) { return x & (-x); }
void build() {
  for (int i = 1; i <= MAX_N; i++) {
    BIT[i] = A[i - 1];
    for (int j = i - 2; j >= i - lowbit(i); j--) BIT[i] += A[j];
  }
}
void edit(int i, int delta) {
  for (int j = i; j <= MAX_N; j += lowbit(j)) BIT[j] += delta;
}
int sum(int k) {
  int ans = 0;
  for (int i = k; i > 0; i -= lowbit(i)) ans += BIT[i];
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> MAX_N;
  for (int i = 0; i < MAX_N; i++) cin >> A[i];
  build();
  cin >> m;
  int a, b;
  while (m--) {
    cin >> a >> b;
    int p = sum(b) - sum(a);
    cout << p / 10 << endl;
  }
  return 0;
}
