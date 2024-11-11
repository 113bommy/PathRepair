#include <bits/stdc++.h>
using namespace std;
long long int n, i, j, k, t, flag, y, r, lo, hi, m, c, ans, x, d, h;
long long int a[500008];
pair<long long int, long long int> p[500008];
map<long long int, long long int> m1;
vector<long long int> v;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> d >> h;
  if (d > 2 * h) {
    cout << "-1\n";
    return 0;
  }
  k = 1;
  if (d >= 2) {
    if (d == h) {
      while (k != (h + 1)) {
        cout << k << " " << k + 1 << endl;
        k++;
      }
      k++;
      while (k <= n) {
        cout << "2 " << k << endl;
        k++;
      }
    } else {
      while (k != (h + 1)) {
        cout << k << " " << k + 1 << endl;
        k++;
      }
      k++;
      cout << 1 << " " << k << endl;
      j = 0;
      while (j < (d - h - 1)) {
        j++;
        cout << k << " " << k + 1 << endl;
        k++;
      }
      k++;
      while (k <= n) {
        cout << "2 " << k << endl;
        k++;
      }
    }
  } else {
    if (d == 1 && n != 2) {
      cout << "-1\n";
      return 0;
    } else {
      j = 2;
      while (j <= n) {
        cout << "1 " << j << endl;
        j++;
      }
    }
  }
}
