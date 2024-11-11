#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main() {
  int i, j, tmp, maxL = -1;
  int n, minA;
  int a[1000];
  int q[1000];
  cin >> n >> minA;
  int front = 0, rear = 0;
  for (i = 0; i < n; i++) {
    cin >> tmp;
    a[rear] = tmp;
    q[rear++] = tmp;
    maxL = max(tmp, maxL);
  }
  int len = 0;
  int cnt;
  int res = 0;
  for (i = minA; i <= maxL; i++) {
    cnt = 0;
    while (front != rear) {
      tmp = q[front++];
      if (tmp < i) continue;
      cnt += tmp / i;
      if (tmp % i != 0) q[rear++] = tmp % i;
    }
    cnt *= i;
    res = max(res, cnt);
    memset(q, 0, sizeof(q));
    for (j = 0; j < n; j++) q[j] = a[j];
    front = 0;
    rear = n;
  }
  cout << res << endl;
  return 0;
}
