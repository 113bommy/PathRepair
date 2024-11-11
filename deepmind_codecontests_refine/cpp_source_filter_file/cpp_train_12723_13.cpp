#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int d[maxn], n;
struct node {
  int a, b;
} data[maxn];
int main() {
  cin >> n;
  d[0] = -1;
  for (int i = 1; i <= n; i++) cin >> d[i];
  sort(d + 1, d + 1 + n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] == d[i - 1])
      data[cnt].b++;
    else {
      cnt++;
      data[cnt].a = d[i];
      data[cnt].b = 1;
    }
  }
  bool flag = 1;
  for (int i = 2; i <= cnt; i++) {
    if (data[i].a - 1 != data[i - 1].a) {
      flag = 0;
      break;
    }
  }
  ++data[1].b, --data[cnt].b;
  if (flag) {
    data[2].b -= data[1].b;
    for (int i = 2; i < cnt; i++) {
      if (data[i].b < 0) {
        flag = 0;
        break;
      } else
        data[i + 1].b -= data[i].b;
    }
    if (data[cnt].b != 0) flag = 0;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
