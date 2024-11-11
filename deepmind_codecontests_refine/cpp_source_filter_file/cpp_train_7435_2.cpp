#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long int joy = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] < 2 || b[i] > a[i] * 2) {
      joy++;
      continue;
    }
    int x = b[i] / 2;
    int y = b[i] - x;
    joy += 1LL * x * y;
  }
  cout << joy << endl;
  return 0;
}
