#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 0.000000001;
using namespace std;
int p1[maxn], p2[maxn], pp[10] = {0, 5, 1, 6, 4, 3, 7, 2};
int main() {
  int n;
  cin >> n;
  if (n % 2)
    puts("NO");
  else {
    cout << "YES" << endl;
    int tmp, tt = n;
    for (int i = 1;; i++) {
      if ((1 << i) <= n)
        tmp = i;
      else
        break;
    }
    for (int i = tmp; i >= 1; i--) {
      if ((1 << i) > tt) continue;
      for (int j = (1 << i); j <= tt; j++) {
        int tmp = (1 << i) - (j - (1 << i) + 1);
        p1[j] = tmp;
        p1[tmp] = j;
      }
      tt = (1 << i) - (tt - (1 << i) + 1) - 1;
    }
    for (int i = 1; i <= n; i++) cout << p1[i] << " ";
    cout << endl;
  }
  int ff = 0;
  for (int i = 1;; i++) {
    if (n == (1 << i)) ff = 1;
    if ((1 << i) >= n) break;
  }
  if (n < 6 || (n > 7 && ff))
    puts("NO");
  else {
    cout << "YES" << endl;
    if (n == 6)
      cout << "3 6 2 5 1 4" << endl;
    else {
      for (int i = 1; i <= 7; i++) p2[i] = pp[i];
      for (int i = 3;; i++) {
        if ((1 << i) > n) break;
        int tmp = (1 << i);
        for (int j = tmp; j < min(tmp * 2 - 1, n); j++) {
          p2[j] = j + 1;
        }
        p2[min(tmp * 2 - 1, n)] = tmp;
      }
      for (int i = 1; i <= n; i++) cout << p2[i] << " ";
      cout << endl;
    }
  }
}
