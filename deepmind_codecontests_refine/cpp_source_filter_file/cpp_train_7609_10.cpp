#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(20);
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int mini = a[0];
  long long int maxi = a[0];
  for (long long int i = 0; i < n; i++)
    if (a[i] > maxi) maxi = a[i];
  for (long long int i = 0; i < n; i++)
    if (a[i] < maxi) mini = a[i];
  long long int x = maxi - mini + 1 - n;
  if (x < 0) x = 0;
  cout << x;
  ;
  return 0;
}
