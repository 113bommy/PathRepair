#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
struct NUM {
  int num;
  int cnt;
  bool operator<(const NUM& Val) const { return Val.cnt > cnt; }
} num[M];
int tmp[M];
int A[M], B[M], C[M];
priority_queue<NUM> que;
int n_case;
void sap(int a, int b, int c) {
  if (a < b) a ^= b ^= a ^= b;
  if (a < c) c ^= a ^= c ^= a;
  if (b < c) c ^= b ^= c ^= b;
  A[n_case] = a;
  B[n_case] = b;
  C[n_case++] = c;
}
int main() {
  int n;
  while (cin >> n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp[i]);
    }
    sort(tmp, tmp + n);
    int s = 0;
    num[s].num = tmp[0];
    num[s].cnt = 1;
    for (int i = 1; i < n; i++) {
      if (tmp[i] == tmp[i - 1]) {
        num[s].cnt++;
      } else {
        num[++s].cnt = 1;
        num[s].num = tmp[i];
      }
    }
    for (int i = 0, ca = n / 3; i <= s; i++) {
      num[i].cnt = (num[i].cnt > ca) ? (ca) : (num[i].cnt);
      que.push(num[i]);
    }
    n_case = 0;
    while (!que.empty()) {
      NUM aa = que.top();
      que.pop();
      if (que.empty()) break;
      NUM bb = que.top();
      que.pop();
      if (que.empty()) break;
      NUM cc = que.top();
      que.pop();
      sap(aa.num, bb.num, cc.num);
      if (--aa.cnt > 0) que.push(aa);
      if (--bb.cnt > 0) que.push(bb);
      if (--cc.cnt > 0) que.push(cc);
    }
    cout << n_case << endl;
    for (int i = 0; i < n_case; i++) {
      printf("%d %d %d\n", A[i], B[i], C[i]);
    }
    while (!que.empty()) que.pop();
  }
  return 0;
}
