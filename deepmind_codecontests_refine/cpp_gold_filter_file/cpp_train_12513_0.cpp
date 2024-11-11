#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, d;
  cin >> n >> d;
  long long a[n], cm[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < d; i++) cm[i] = a[i];
  for (int i = d; i < n; i++) cm[i] = a[i] + cm[i - d];
  for (int i = 0; i < n; i++) {
    cm[i + 1] += cm[i];
    cout << cm[i] << " ";
  }
  cout << endl;
}
