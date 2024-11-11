#include <bits/stdc++.h>
using namespace std;
int n, d, l, a[110];
int main() {
  while (cin >> n >> d >> l) {
    int pos, neg;
    neg = n / 2;
    pos = n - n / 2;
    bool rev = d <= 0;
    int t = l;
    if (d) l = min(abs(d), l);
    if (rev == false and pos * t - neg < d)
      cout << -1 << endl;
    else if (rev and neg * t - pos < -d)
      cout << -1 << endl;
    else {
      pos = neg = 0;
      if (rev == false) {
        for (int i = 0; i < n; i++)
          if (i % 2)
            a[i] = 1, neg++;
          else
            a[i] = l, pos += l;
        int i = 1;
        while (pos - neg > d) {
          a[i] += min(l - 1, pos - neg - d);
          neg += min(l - 1, pos - neg - d);
          i += 2;
        }
      } else {
        for (int i = 0; i < n; i++)
          if (i % 2 == 0)
            a[i] = 1, neg++;
          else
            a[i] = l, pos += l;
        int i = 0;
        d = -d;
        while (pos - neg > d) {
          a[i] += min(l - 1, pos - neg - d);
          neg += min(l - 1, pos - neg - d);
          i += 2;
        }
      }
      for (int i = 0; i < n; i++) printf("%d  ", a[i]);
      cout << endl;
    }
  }
  return 0;
}
