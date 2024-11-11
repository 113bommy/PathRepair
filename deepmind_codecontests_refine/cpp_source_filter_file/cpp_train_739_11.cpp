#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < pow(2, n); i++) {
    vector<int> v;
    for (j = i; j != 0; j /= 2) v.push_back(j % 2);
    long long int s = 0;
    for (j = 0; j < n; j++) {
      if (j >= v.size())
        s += a[j];
      else {
        if (v[j] == 1)
          s -= a[j];
        else
          s += a[j];
      }
    }
    if (s % 60 == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
