#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> arr[100], g[100];
int main() {
  long long n, d, h;
  cin >> n >> d >> h;
  long long x = n;
  if (d - h > h)
    cout << "-1";
  else if (n > 2 && d < 2)
    cout << "-1";
  else {
    for (long long i = 2; i <= h + 1; i++) {
      cout << i - 1 << ' ' << i << endl;
    }
    long long tmp = 0;
    if (d > h) {
      cout << "1 " << h + 2 << endl;
      tmp = 1;
    }
    for (long long i = h + 3; i <= d + 1; i++) {
      cout << i - 1 << ' ' << i << endl;
    }
    if (tmp == 1) {
      for (long long i = max(d + 2, h + 3); i <= n; i++) {
        cout << "1 " << i << endl;
      }
    } else {
      for (long long i = max(d + 1, h + 2); i <= n; i++) {
        cout << "2 " << i << endl;
      }
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
