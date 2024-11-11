#include <bits/stdc++.h>
using namespace std;
void countFreq(int a[], int n) {}
int main() {
  long long int t, n, i, max = 0, min = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int c = 0;
    for (i = n - 1; i >= 0; i--) {
      if (a[i - 1] > c) c++;
    }
    cout << c << endl;
  }
}
