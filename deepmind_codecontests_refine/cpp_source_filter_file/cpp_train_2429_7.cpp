#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char c;
  int n, sum1 = 0, sum2 = 0;
  cin >> n;
  int m[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> c;
    m[i] = c - '0';
  }
  for (int i = 0; i < n; i++) {
    cin >> c;
    b[i] = c - '0';
  }
  sort(m, m + n);
  sort(b, b + n);
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (m[i] < b[i]) flag = false;
  }
  if (!flag) {
    flag = true;
    for (int i = 0; i < n; i++) {
      if (m[i] > b[i]) flag = false;
    }
  } else {
    cout << "Yes";
    return 0;
  }
  if (flag) {
    cout << "Yes";
    return 0;
  }
  cout << "No";
  return 0;
}
