#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr[1001][2], ne[1001][2], l;
  int i;
  int n;
  cin >> arr[0][0] >> arr[0][1];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  ne[0][0] = arr[0][0];
  ne[0][1] = arr[0][1];
  for (i = 1; i <= n; i++) {
    if (arr[i][0] != ne[i - 1][0])
      l = ne[i - 1][0];
    else if (arr[i][0] != ne[i - 1][1])
      l = ne[i - 1][1];
    ne[i][0] = l;
    ne[i][1] = arr[i][1];
  }
  for (i = 0; i <= n; i++) cout << ne[i][0] << " " << ne[i][1] << endl;
  return (0);
}
