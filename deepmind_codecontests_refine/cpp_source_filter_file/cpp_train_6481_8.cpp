#include <bits/stdc++.h>
using namespace std;
bool Sorted(vector<long long int>& arr, long long int n) {
  if (n == 0 || n == 1) return true;
  for (long long int i = 1; i < n; i++)
    if (arr[i - 1] > arr[i]) return false;
  return true;
}
int main() {
  long long int a, b, i, c, d, n, e, g, r, j, k, l, ff = 1, h = 0, m = 4, o = 0,
                                                    tt = 0, ans = 0, p;
  string w, y, z;
  char x;
  scanf("%lld", &tt);
  while (tt--) {
    vector<long long int> v;
    cin >> a;
    n = a;
    o = 1;
    while (a--) {
      scanf("%lld", &b);
      v.push_back(b);
      if (b != 1) o = 0;
    }
    if (o) {
      if (n % 2 == 0) {
        cout << "Second" << endl;
        continue;
      } else {
        cout << "First" << endl;
        continue;
      }
    }
    if (v[0] > 1) {
      cout << "First" << endl;
      continue;
    }
    ff = 1;
    for (i = 0; i < n; i++) {
      if (v[i] >= 1) {
        if (ff % 2 == 0) {
          cout << "Second" << endl;
          break;
        } else {
          cout << "First" << endl;
          break;
        }
      } else {
        ff++;
      }
    }
  }
  return 0;
}
