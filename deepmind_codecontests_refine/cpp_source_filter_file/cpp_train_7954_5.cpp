#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double eps = 1e-8;
const int maxn = 3000000;
char a[maxn];
int main() {
  while (scanf("%s", a) == 1) {
    int len = strlen(a);
    int mid;
    for (int i = (0); i < (len); ++i)
      if (a[i] == '^') mid = i;
    int l = 0, r = 0;
    for (int i = (0); i < (mid); ++i) {
      if (a[i] != '=') l += (mid - i) * (a[i] - '0');
    }
    for (int i = (mid + 1); i < (len); ++i) {
      if (a[i] != '=') r += (i - mid) * (a[i] - '0');
    }
    if (r == l)
      cout << "balance\n";
    else {
      if (l > r)
        cout << "left\n";
      else
        cout << "right" << endl;
    }
  }
  return 0;
}
