#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, a, b, k;
char river;
int pos[maxn];
int num[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b >> k;
  int cnt = 0;
  pos[cnt++] = 0;
  for (int i = 0; i < n; i++) {
    cin >> river;
    if (river == '1') {
      pos[cnt++] = i + 1;
    }
  }
  pos[cnt++] = n + 1;
  int tot = 0;
  for (int i = 1; i < cnt; i++) {
    int tmp = pos[i] - pos[i - 1] - 1;
    num[i - 1] = tmp;
    tot += tmp / b;
  }
  cout << max(0, tot - a + 1) << endl;
  int p = 0;
  for (; num[p] <= 0; p++)
    ;
  int hit = pos[p];
  p++;
  for (int i = 0; i < tot - a + 1; i++) {
    if (pos[p] - hit > b) {
      hit += b;
    } else {
      for (; num[p] <= 0; p++)
        ;
      hit = pos[p] + b;
      p++;
    }
    cout << hit << " ";
  }
  cout << endl;
  return 0;
}
