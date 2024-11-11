#include <bits/stdc++.h>
using namespace std;
int n, mas[300009], ans, i;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> mas[i];
  }
  sort(mas + 1, mas + n + 1);
  for (i = 1; i <= n; i++) {
    ans += abs(i[mas] - i);
  }
  cout << ans;
}
