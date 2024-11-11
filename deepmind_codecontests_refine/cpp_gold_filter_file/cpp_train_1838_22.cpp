#include <bits/stdc++.h>
using namespace std;
long long num[100];
long long k, p;
long long mark[100];
void check(int p) {
  if (p <= 90 && mark[p] >= k) {
    mark[p + 1] += k - mark[p] / k;
    mark[p + 2] += 1;
    mark[p] %= k;
    check(p + 1);
    check(p + 2);
  } else
    return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  while (cin >> p >> k) {
    memset(mark, 0, sizeof(mark));
    num[0] = 1;
    int cur = 0;
    while (num[cur] < p) cur++, num[cur] = num[cur - 1] * k;
    for (int i = cur; i >= 0; --i) {
      if (p / num[i] != 0) {
        mark[i] = p / num[i];
        if (i % 2 == 1) {
          mark[i] = k - mark[i];
          mark[i + 1]++;
          check(i + 1);
        }
        p %= num[i];
      } else {
        mark[i] = 0;
      }
    }
    cur = 80;
    while (mark[cur] == 0) cur--;
    cout << cur + 1 << endl;
    for (int i = 0; i < cur; i++) cout << mark[i] << " ";
    cout << mark[cur] << endl;
  }
  return 0;
}
