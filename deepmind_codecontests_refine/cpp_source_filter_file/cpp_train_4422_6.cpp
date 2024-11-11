#include <bits/stdc++.h>
using namespace std;
int a[3100], b[3100];
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    long long j = 0;
    while (a[i] != b[j]) j++;
    swap(b[i], b[j]);
    cout << i << ' ' << j << endl;
  }
}
