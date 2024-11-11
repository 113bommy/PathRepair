#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum % 4;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    bool fr[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      fr[i] = 0;
    }
    sort(a.begin(), a.end());
    int flg = 0;
    long long int sum = 0;
    long long int x = a[n - 1];
    long long int y = 0, z = 0;
    fr[n - 1] = 1;
    int g = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (x % a[i] == 0) {
        fr[i] = 1;
        if (x / a[i] == 2 && g == 0) g++;
        if (x / a[i] == 3 && g == 1) g++;
        if (x / a[i] == 5 && g == 2) g++;
      } else if (flg == 0) {
        flg = 1;
        y = i;
      }
    }
    if (flg == 1) {
      fr[y] = 1;
      int x1 = a[y];
      flg = 0;
      for (int i = y - 1; i >= 0; i--) {
        if (x1 % a[i] == 0 && fr[i] == 0)
          fr[i] = 1;
        else if (flg == 0 && fr[i] == 0) {
          flg = 1;
          z = i;
        }
      }
      y = a[y];
      if (flg == 1) {
        fr[z] = 1;
        x1 = a[z];
        flg = 0;
        for (int i = z - 1; i >= 0; i--) {
          if (x1 % a[i] == 0 && fr[i] == 0) fr[i] = 1;
        }
        z = a[z];
      }
    }
    long long int r = x + y + z;
    if (g == 3) {
      r = max(r, (x / 2) + (x / 3) + (x / 5));
    }
    cout << r << endl;
  }
  return 0;
}
