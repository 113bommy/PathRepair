#include <bits/stdc++.h>
using namespace std;
long long int A, v[300000];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) A = A + (i + 1) * v[i];
  cout << A - v[n];
}
