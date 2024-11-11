#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sum = 0;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) sum = sum + a[i];
  int max = a[0];
  for (int i = 0; i < n; i++)
    if (a[i] > max) max = a[i];
  if (sum % 2)
    cout << "NO";
  else if (sum / 2 > max)
    cout << "YES";
  else if (sum / 2 < max)
    cout << "NO";
  return 0;
}
