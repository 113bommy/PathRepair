#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n][6];
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 6; j++) {
      cin >> a[i][j];
      s.insert(a[i][j]);
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 6; j++) {
      long long int temp = a[i][j];
      for (long long int k = i + 1; k < n; k++) {
        for (long long int l = 0; l < 6; l++) {
          long long int an = temp * 10 + a[k][l];
          long long int at = a[k][l] * 10 + temp;
          s.insert(an);
          s.insert(at);
        }
      }
    }
  }
  long long int i = 1;
  while (s.find(i) != s.end()) {
    i++;
  }
  cout << i - 1;
  return 0;
}
