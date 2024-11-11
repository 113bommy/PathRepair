#include <bits/stdc++.h>
using namespace std;
int p[100005] = {};
int n;
int main() {
  cin >> n;
  if (n % 4 != 0 && n % 4 != 1) {
    cout << "-1" << endl;
    return 0;
  }
  for (int i = 1; i <= n / 2; i += 2) {
    p[i] = i + 1;
    p[i + 1] = n - i + 1;
    p[n - i + 1] = n - i;
    p[n - i] = i;
  }
  if (n % 2 == 1) p[n / 2 + 1] = n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    cout << p[i] << " ";
  }
  return 0;
}
