#include <bits/stdc++.h>
using namespace std;
class point {
 public:
  long long int x;
  long long int y;
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int arrb[n], arrg[m];
  for (long long int i = 0; i < n; i++) {
    cin >> arrb[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> arrg[i];
  }
  sort(arrb, arrb + n);
  sort(arrg, arrg + n);
  long long int lmao = 0;
  for (long long int i = 0; i < m; i++) {
    if (binary_search(arrb, arrb + n, arrg[i])) {
    } else {
      lmao++;
    }
  }
  if (arrb[n - 1] > arrg[0] || (lmao > (m - 1) * n)) {
    cout << "-1" << endl;
    return 0;
  } else {
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      ans += arrb[i];
    }
    ans *= m;
    long long int count = 0;
    for (long long int i = 0; i < m; i++) {
      if (binary_search(arrb, arrb + n, arrg[i])) {
      } else {
        ans += arrg[i];
        count++;
      }
    }
    long long int sub = 0;
    long long int x = 0;
    long long int y = 0;
    if (m - 1 != 0) {
      x = count / (m - 1);
      y = count % (m - 1);
    }
    long long int k = n - 1;
    while (x--) {
      sub += arrb[k];
      k--;
    }
    sub *= (m - 1);
    sub += (y)*arrb[k];
    cout << ans - sub << endl;
  }
}
