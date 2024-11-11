#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mas[100000];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> mas[i];
  k = k + mas[1] - 1;
  for (int i = 1; i < n; i++) {
    if (mas[i] <= mas[i + 1]) k = k + mas[i + 1] - mas[i];
    if (mas[i] > mas[i + 1]) k = k + n - mas[i] + mas[i + 1];
  }
  cout << k - 1;
}
