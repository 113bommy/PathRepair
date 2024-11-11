#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long *p = new long[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(p[i] - (i + 1));
  }
  cout << sum << endl;
  return 0;
}
