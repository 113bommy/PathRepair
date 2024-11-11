#include <bits/stdc++.h>
using namespace std;
long long arr[10];
int main() {
  string s;
  long long i, j, n, m, t;
  long long mx = 0;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> s;
    for (j = 0; j < 7; j++) {
      arr[j] += s[j] - '0';
      mx = max(mx, arr[i]);
    }
  }
  cout << mx << endl;
}
