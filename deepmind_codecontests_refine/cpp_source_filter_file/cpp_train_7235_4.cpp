#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  long m = abs(ar[0]);
  for (int i = 1; i < n; i++) {
    m += abs(ar[i] - ar[i - 1]);
  }
  cout << m << endl;
}
