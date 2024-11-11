#include <bits/stdc++.h>
using namespace std;
bool cmp(long long int a, long long int b) { return a > b; }
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int *a = new long long int[n];
  long long int *b = new long long int[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m, cmp);
  long long int sum = 0;
  for (int i = 0; i < min(n, m); i++) {
    if (a[i] >= b[i]) {
      break;
    }
    sum += (b[i] - a[i]);
  }
  cout << sum << endl;
  return 0;
}
