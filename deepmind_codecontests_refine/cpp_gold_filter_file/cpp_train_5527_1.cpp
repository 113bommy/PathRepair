#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2), present(n + 2);
  a[0] = 0;
  present[0] = 1;
  a[n + 1] = m;
  present[n + 1] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long maxa = 0;
  for (int i = 1; i <= n; i++) {
    present[i] = present[i - 1] ^ 1;
  }
  for (int i = 0; i <= n; i++) {
    if (present[i] == 1) maxa += a[i + 1] - a[i];
  }
  vector<long long> prefix0(n + 2, 0), prefix1(n + 2, 0);
  for (int i = 1; i <= n + 1; i++) {
    if (present[i - 1] == 1)
      prefix0[i] = (a[i] - a[i - 1]) + prefix0[i - 1];
    else
      prefix0[i] = prefix0[i - 1];
  }
  for (int i = 1; i <= n + 1; i++) {
    if (present[i - 1] == 0)
      prefix1[i] = (a[i] - a[i - 1]) + prefix1[i - 1];
    else
      prefix1[i] = prefix1[i - 1];
  }
  long long temp = 0;
  for (int i = 1; i <= n; i++) {
    if (present[i] == 0) {
      if (a[i] - a[i - 1] > 1) {
        temp = prefix0[i] - 1;
        temp += (prefix1[n + 1] - prefix1[i]);
        maxa = max(temp, maxa);
      }
      if (a[i + 1] - a[i] > 1) {
        temp = prefix0[i] + (a[i + 1] - a[i] - 1);
        temp += (prefix1[n + 1] - prefix1[i + 1]);
        maxa = max(temp, maxa);
      }
    } else {
      if (a[i] - a[i - 1] > 1) {
        temp = prefix0[i - 1] + +(a[i] - a[i - 1] - 1);
        ;
        temp += (prefix1[n + 1] - prefix1[i]);
        maxa = max(temp, maxa);
      }
      if (a[i + 1] - a[i] > 1) {
        temp = prefix0[i + 1] - 1;
        temp += (prefix1[n + 1] - prefix1[i + 1]);
        maxa = max(temp, maxa);
      }
    }
  }
  cout << maxa << "\n";
  return 0;
}
