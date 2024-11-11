#include <bits/stdc++.h>
using namespace std;
long long int ar[600005];
long long int cnt[600005];
long long int ans[600005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int i, j;
  long long int n;
  cin >> n;
  long long int ar[2 * n], to = 0;
  for (i = 0; i < 2 * n; i++) {
    cin >> ar[i];
    to += ar[i];
  }
  sort(ar, ar + 2 * n);
  long long int sum = 0;
  for (i = 0; i < n; i++) sum += ar[i];
  if (2 * sum == to) return !(cout << -1);
  for (i = 0; i < 2 * n; i++) cout << ar[i] << " ";
  return 0;
}
