#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int c = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] > c) {
      c++;
    }
  }
  cout << c << endl;
}
