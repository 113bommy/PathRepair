#include <bits/stdc++.h>
using namespace std;
int t;
int ta[3000], n, m, x;
int k, li;
bool tt[4000];
void ple() {
  for (int i = 0; i <= 3 * n; i++) tt[i] = false;
  tt[0] = true;
  int ma = 0;
  for (int i = 0; i < k; i++) {
    for (int j = ma; j >= 0; j--) {
      if (tt[j]) tt[j + ta[i]] = true;
    }
    ma += ta[i];
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    k = 0;
    cin >> m;
    li = 1;
    for (int j = 1; j < 2 * n; j++) {
      cin >> x;
      if (x > m) {
        m = x;
        ta[k] = li;
        k++;
        li = 1;
      } else {
        li++;
      }
    }
    ta[k] = li;
    k++;
    ple();
    if (tt[n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
