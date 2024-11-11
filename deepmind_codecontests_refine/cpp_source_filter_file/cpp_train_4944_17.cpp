#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
queue<int> q1, q2;
int a[12], b[12];
int main() {
  int n, k1, k2, t;
  cin >> n;
  cin >> k1;
  for (int i = 0; i < k1; i++) cin >> a[i];
  cin >> k2;
  for (int i = 0; i < k2; i++) cin >> b[i];
  for (int i = 0; i <= k1; i++) q1.push(a[i]);
  for (int i = 0; i <= k2; i++) q2.push(b[i]);
  int cnt = 0;
  while (!q1.empty() && !q2.empty() && cnt < 1000000) {
    int x1 = q1.front(), x2 = q2.front();
    q1.pop();
    q2.pop();
    if (x1 > x2) {
      q1.push(x2);
      q1.push(x1);
    } else {
      q2.push(x1);
      q2.push(x2);
    }
    cnt++;
  }
  if (cnt == 1000000)
    printf("-1");
  else if (!q1.empty())
    printf("%d 1", cnt);
  else
    cout << cnt << " 2";
  return 0;
}
