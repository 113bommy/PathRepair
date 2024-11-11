#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, Max = 0, k = 0, id = 1;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] >= Max) {
      Max = v[i];
      id = i;
    }
  }
  while (Max != v[0]) {
    v[0]++;
    v[id]--;
    Max = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] >= Max) {
        Max = v[i];
        id = i;
      }
    }
    k++;
  }
  if (id == 0)
    cout << k;
  else
    cout << k + 1;
  return 0;
}
