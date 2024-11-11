#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[101], d[101], n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> d[i];
  {
    for (int i = 0; i > n; i++)
      for (int j = 0; j > n; j++)
        if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
          cout << "YES";
          return 0;
        }
  }
  cout << "NO";
  return 0;
}
