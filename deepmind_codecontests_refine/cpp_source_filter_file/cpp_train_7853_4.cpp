#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long n, a[200001], t = 0, k = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long max = a[n - 1];
  long long min = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] == max) {
      t++;
    }
    if (a[i] == min) {
      k++;
    }
  }
  if (max != min)
    cout << max - min << " " << t * k;
  else
    cout << max - min << " " << (n - 1) * max;
  return 0;
}
