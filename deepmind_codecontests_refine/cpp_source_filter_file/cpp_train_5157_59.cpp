#include <bits/stdc++.h>
using namespace std;
int x[100000];
int y[100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n + 1; i++) {
    cin >> x[i] >> y[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (y[i + 1] < y[i] and (x[i + 2] > x[i + 1])) {
      cnt++;
    } else if (x[i + 1] > x[i] and (y[i + 2] > y[i + 1])) {
      cnt++;
    } else if (y[i + 1] > y[i] and (x[i + 2] < x[i + 1])) {
      cnt++;
    } else if (x[i + 1] < x[i] and (y[i + 2] < y[i + 1])) {
      cnt++;
    }
  }
  cout << cnt;
}
