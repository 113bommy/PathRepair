#include <bits/stdc++.h>
using namespace std;
long long int A, v[300000];
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> v[i];
  sort(v + 1, v + n + 1);
  for (i = 1; i <= n; i++) A = A + (i + 1) * v[i];
  cout << A - v[n];
}
