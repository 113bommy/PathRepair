#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int count = 0;
  int j = -1;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      count++;
      j = i + 1;
    }
  }
  if (count == 0)
    cout << 0;
  else if (count == 1 && v[0] > v[n - 1])
    cout << n - j;
  else
    cout << -1;
}
