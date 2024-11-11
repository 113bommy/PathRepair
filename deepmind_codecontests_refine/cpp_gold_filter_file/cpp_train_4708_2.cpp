#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  int t;
  cin >> t;
  for (int titr = 0; titr < t; titr++) {
    int n;
    int a[2001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
      bool o = 0;
      bool e = 0;
      for (int i = 0; i < n; i++) {
        if (o && e) break;
        if (a[i] % 2) {
          o = 1;
        } else {
          e = 1;
        }
      }
      if (o && e)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      bool o = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
          o = 1;
          break;
        }
      }
      if (o)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
