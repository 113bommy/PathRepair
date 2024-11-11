#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++)
    for (int j = i + i; j <= n; j++) ans = ans + j / i;
  cout << ans * 4;
}
