#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const int inf = (1 << 31) - 1;
const int hinf = 0x3f3f3f3f;
const int mod = 1000000007;
int dat[110000];
int d2[110000];
int n;
int main() {
  cin >> n;
  if (n == 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> dat[i];
  int f1 = 1, f2 = 1;
  for (int i = 1; i < n; i++)
    if (dat[i] < dat[i + 1]) f1 = 0;
  for (int i = 1; i < n; i++)
    if (dat[i] > dat[i + 1]) f2 = 0;
  if (f1 == 1 || f2 == 1) {
    if (n < 3) {
      puts("-1");
      return 0;
    }
  }
  int cnt = 0;
  for (int j = 1; j < n; j++)
    if (dat[j] != dat[j + 1]) cnt = j;
  if (cnt == 0) {
    puts("-1");
    return 0;
  }
  if (f1 == 1 || f2 == 1) {
    cout << cnt << " " << cnt + 1 << endl;
    return 0;
  }
  int a, b;
  srand(time(0));
  for (int i = 1; i <= 1000; i++) {
    if (i == 1)
      a = cnt, b = cnt + 1;
    else
      a = rand() % n + 1;
    b = rand() % n + 1;
    if (a == b || dat[a] == dat[b]) {
      i--;
      continue;
    }
    for (int j = 1; j <= n; j++) d2[j] = dat[j];
    swap(d2[a], d2[b]);
    int f1 = 1, f2 = 1;
    for (int j = 1; j < n; j++)
      if (d2[j] < d2[j + 1]) f1 = 0;
    for (int j = 1; j < n; j++)
      if (d2[j] > d2[j + 1]) f2 = 0;
    if (f1 == 0 && f2 == 0) {
      cout << a << " " << b << endl;
      return 0;
    }
  }
  puts("-1");
}
