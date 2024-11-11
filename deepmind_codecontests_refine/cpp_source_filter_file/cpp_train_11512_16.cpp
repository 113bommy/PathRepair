#include <bits/stdc++.h>
using namespace std;
int tem[200005];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tem[i]);
    if (tem[i] < 0) cnt++;
  }
  if (cnt > k) {
    puts("-1");
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (tem[i] < 0 && tem[i - 1] >= 0) sum += 2;
  }
  int s = 0;
  for (int i = 1; i <= n; i++) {
    if (tem[i] < 0) {
      s = i;
      break;
    }
  }
  int con = 0;
  for (int i = 1; i <= n; i++) {
    if (tem[i] >= 0) {
      if (tem[i - 1] < 0)
        con = 1;
      else
        con++;
    } else {
      if (con) {
        pq.push(con);
        con = 0;
      }
    }
  }
  int temp = cnt;
  while (!pq.empty()) {
    if (temp + pq.top() <= k) {
      temp += pq.top();
      pq.pop();
      sum -= 2;
    } else
      break;
  }
  if (temp + con <= k) sum--;
  printf("%d\n", sum);
  return 0;
}
