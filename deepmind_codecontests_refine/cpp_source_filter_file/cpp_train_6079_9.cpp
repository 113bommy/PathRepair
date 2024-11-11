#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int len = sizeof(s);
  long long int m;
  cin >> m;
  long long int a[100001];
  long long int sum[100001];
  sum[0] = 0;
  a[0] = 0;
  for (long long int i = 1; i < len - 1; i++) {
    if (s[i] == s[i - 1]) {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
    sum[i] = a[i] + sum[i - 1];
  }
  for (long long int i = 0; i < m; i++) {
    long long int r, l;
    cin >> r >> l;
    cout << (sum[l - 1] - sum[r - 1]) << endl;
  }
}
