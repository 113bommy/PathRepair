#include <bits/stdc++.h>
using namespace std;
int a[100002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int k;
  cin >> k;
  int x = k - n + 1;
  int y = 1;
  if (x < 0) {
    y = 0;
    x = k;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        cout << x << " ";
      else
        cout << y << " ";
    }
    cout << endl;
  }
  cout << endl;
}
