#include <bits/stdc++.h>
using namespace std;
struct sans {
  long long int t1;
  long long int b1;
};
bool func(sans s1, sans s2) { return s1.b1 < s2.b1; }
long long int a1[100000 + 1];
long long int comp[100000 + 1];
long long int ans[100000 + 1];
int main() {
  long long int t, n, w, max1, flag, count;
  cin >> t;
  while (t--) {
    cin >> n;
    count = 1;
    max1 = 1;
    for (long long int i = 1; i <= n; i++) comp[i] = 0;
    ;
    flag = 0;
    for (long long int i = 1; i <= n; i++) {
      cin >> w;
      a1[i] = w;
    }
    for (long long int i = 1; i <= n; i++) {
      if (comp[a1[i]] == 1) {
        while (comp[max1] == 1) {
          max1++;
          if (max1 >= a1[i]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          comp[max1] = 1;
          ans[count] = max1;
          count++;
        } else {
          cout << -1 << endl;
          break;
        }
      } else {
        comp[a1[i]] = 1;
        ans[count] = a1[i];
        count++;
      }
    }
    if (flag == 0) {
      for (long long int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }
}
