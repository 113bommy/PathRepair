#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  int p[n];
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(p, 0, sizeof(p));
  p[0] = 0;
  p[1] = 0;
  int maxi = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == a[i - 1] + a[i - 2]) {
      p[i] = p[i - 1] + 1;
    } else {
      p[i] = 0;
    }
    maxi = max(p[i], maxi);
  }
  if (n == 1) {
    cout << "1" << endl;
  } else if (n == 2) {
    cout << "2" << endl;
  } else {
    cout << maxi + 2 << endl;
  }
  return 0;
}
