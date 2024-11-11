#include <bits/stdc++.h>
const double eps = (1e-10);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
long long setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
long long inf = (1ll << 62);
const int MAX = 1000009;
priority_queue<long long> pqR, pqC;
int C[MAX], R[MAX];
long long rows[MAX], cls[MAX];
int main() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) {
    long long no;
    for (int j = 1; j <= m; j++) cin >> no, C[j] += no, R[i] += no;
  }
  for (int i = 1; i <= n; i++) {
    pqR.push(R[i]);
  }
  for (int i = 1; i <= m; i++) pqC.push(C[i]);
  long long re;
  for (int i = 1; i <= k; i++) {
    rows[i] = pqR.top() + rows[i - 1];
    re = pqR.top() - (m * p);
    pqR.push(re);
    pqR.pop();
    cls[i] = pqC.top() + cls[i - 1];
    re = pqC.top() - (n * p);
    pqC.push(re);
    pqC.pop();
  }
  long long mx = -inf;
  for (int i = 0; i <= k; i++) {
    mx = max(mx, rows[i] + cls[k - i] - (k - i) * i * p);
  }
  cout << mx << endl;
}
