#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 4 > 1) {
    cout << "-1\n";
    return 0;
  }
  int p[n];
  if (n % 4 == 1) {
    p[n / 2] = (n + 1) / 2;
  }
  if (n != 1) {
    p[0] = 2;
    p[1] = n;
    p[n - 2] = 1;
    p[n - 1] = n - 1;
  }
  for (int i = 2, j = n - 4; i < n / 2; i += 2, j -= 2) {
    p[i] = p[i - 2] + 2;
    p[i + 1] = p[i - 1] - 2;
    p[j] = p[i] - 1;
    p[j + 1] = p[i + 1] - 1;
  }
  for (int i : p) cout << i << " ";
  cout << endl;
  return 0;
}
