#include <bits/stdc++.h>
using namespace std;
int d[110][110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> d[i][j];
  vector<int> a(n);
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < n; j++) {
      int c = 0;
      for (int k = 0; k < n; k++)
        if (k != j && (d[j][k] & (1 << i))) c++;
      if (c > 0) a[j] = a[j] | (1 << i);
    }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
