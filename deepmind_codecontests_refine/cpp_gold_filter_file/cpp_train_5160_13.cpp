#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  int c1, c2, c3;
  cout << "? 1 2" << endl;
  fflush(stdout);
  cin >> c1;
  cout << "? 2 3" << endl;
  cin >> c2;
  fflush(stdout);
  cout << "? 1 3" << endl;
  cin >> c3;
  fflush(stdout);
  a[1] = (c1 + c2 - c3) / 2;
  a[0] = c1 - a[1];
  a[2] = c2 - a[1];
  for (int i = 4; i <= n; i++) {
    int h;
    cout << "? 2 " << i << endl;
    cin >> h;
    fflush(stdout);
    a[i - 1] = h - a[1];
  }
  cout << "! ";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
