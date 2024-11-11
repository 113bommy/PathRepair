#include <bits/stdc++.h>
using namespace std;
int sum[200001];
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool bo = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (bo) {
      if (a[i] + b[i] - 'a' - 'a' + 1 >= 26) {
        bo = 1;
        sum[i] = a[i] + b[i] - 'a' - 'a' - 25;
      } else {
        bo = 0;
        sum[i] = a[i] + b[i] - 'a' - 'a' + 1;
      }
    } else {
      if (a[i] + b[i] - 'a' - 'a' >= 26) {
        bo = 1;
        sum[i] = a[i] + b[i] - 'a' - 'a' - 26;
      } else {
        sum[i] = a[i] + b[i] - 'a' - 'a';
      }
    }
  }
  if (bo) sum[0] += 26;
  bo = 0;
  for (int i = 0; i < n; i++) {
    if (bo) sum[i] += 26;
    if (sum[i] & 1) {
      bo = 1;
      cout << char(sum[i] / 2 + 'a');
    } else {
      bo = 0;
      cout << char(sum[i] / 2 + 'a');
    }
  }
}
