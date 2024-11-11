#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  int c = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (ar[i] >= sum) {
      c++;
      sum += ar[i];
    }
  }
  cout << c << endl;
  return 0;
}
