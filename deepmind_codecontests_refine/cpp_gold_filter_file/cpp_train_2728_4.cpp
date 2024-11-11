#include <bits/stdc++.h>
using namespace std;
using namespace std;
void start() {}
void sober() {
  int n;
  cin >> n;
  int sum = 0;
  int sum1 = 0;
  int* a = new int[n];
  int* b = new int[n];
  int min1;
  int s = 0;
  int end = 0;
  int foo = 0;
  int max1 = 0;
  bool flag = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    if (abs(a[i + 1] - a[i]) >= 2) {
      cout << "YES" << endl;
      flag = 1;
      cout << i + 1 << " " << i + 2 << endl;
      break;
    }
  }
  if (!flag) cout << "NO" << endl;
}
int main() {
  start();
  int t;
  cin >> t;
  while (t--) sober();
}
