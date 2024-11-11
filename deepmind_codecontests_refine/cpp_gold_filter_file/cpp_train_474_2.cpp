#include <bits/stdc++.h>
using namespace std;
long long int a[1000000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  for (auto &x : a) cin >> x;
  long long int days = 0;
  for (long long int i = 0; i < n; i++) days += ceil(a[i] * 1.0 / k);
  cout << (int)ceil(days / 2.0);
}
