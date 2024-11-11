#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], d[n], spit[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> d[i];
    spit[i] = (x[i] + d[i]);
  }
  bool result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = (i + 1); j < n; j++) {
      if ((spit[j] == x[i]) && (spit[i] == x[j])) {
        result = 1;
        break;
      }
    }
  }
  if (result)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
