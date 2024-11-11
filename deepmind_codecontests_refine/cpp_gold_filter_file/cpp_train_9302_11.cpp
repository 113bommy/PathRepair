#include <bits/stdc++.h>
using namespace std;
int n, d, l;
int main() {
  while (cin >> n >> d >> l) {
    vector<int> arr(n);
    int po = (n + 1) / 2, ne = (n / 2);
    int nval, pval, div, rem;
    if (po * l - ne < d) {
      cout << -1;
      goto end;
    }
    if (po - ne * l > d) {
      cout << -1;
      goto end;
    }
    if (d >= 0) {
      pval = d + ne;
      div = pval / po, rem = pval % po;
    } else {
      nval = po - d;
      div = nval / ne, rem = nval % ne;
    }
    for (int i = 0; i < n; i++) {
      if ((i & 1) == (d < 0)) {
        int num = div;
        if (rem) num++, --rem;
        if (num == 0) ++num, ++arr[i - 1];
        if (num > l || (i > 0 && arr[i - 1] > l)) {
          cout << -1;
          goto end;
        }
        arr[i] = num;
      } else
        arr[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
  end:
    cout << endl;
  }
  return 0;
}
