#include <bits/stdc++.h>
using namespace std;
int n, sum, a[100010], d;
int main() {
  cin >> n >> sum;
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    a[v1]++;
    a[v2]++;
    if (a[v1] == 1) d++;
    if (a[v1] == 2) d--;
    if (a[v2] == 1) d++;
    if (a[v2] == 2) d--;
  }
  cout.precision(40);
  cout << 2 * ((long double)sum) / d;
}
