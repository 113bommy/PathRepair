#include <bits/stdc++.h>
using namespace std;
struct quick {
  int deliver;
  int self;
};
quick d[200000];
int main() {
  int n, a, b;
  int i, j, m, k, p, q, max;
  long long l, r, sum, middle;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    max = 0;
    for (j = 0; j < m; j++) {
      cin >> d[j].deliver;
      if (max < d[j].deliver) max = d[j].deliver;
    }
    for (j = 0; j < m; j++) {
      cin >> d[j].self;
    }
    l = 0;
    r = max;
    while (l < r) {
      middle = (l + r) / 2;
      sum = 0;
      for (j = 0; j < m; j++)
        if (middle < d[j].deliver) sum += d[j].self;
      if (sum <= middle)
        r = middle;
      else
        l = middle + 1;
    }
    cout << l << endl;
  }
  return 0;
}
