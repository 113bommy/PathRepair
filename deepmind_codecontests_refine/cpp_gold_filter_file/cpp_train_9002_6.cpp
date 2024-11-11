#include <bits/stdc++.h>
using namespace std;
int arr[110][110];
int main() {
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = min(b, d); i <= max(b, d); i++)
      for (int j = min(a, c); j <= max(a, c); j++) arr[i][j]++;
  }
  int p = 0;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++) p += arr[i][j];
  cout << p << endl;
}
