#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
long long int a[maxn], n, s, x;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= n; i++) s += a[i] / 2;
  cout << s / 2;
  return 0;
}
