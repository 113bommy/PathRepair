#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int has = 0;
  ;
  cin >> n;
  int d[n - 1];
  for (int i = 0; i < n - 1; i++) cin >> d[i];
  int a, b;
  cin >> a >> b;
  int m;
  has = 0;
  for (int m = 0; m < b - a; m++) {
    has = has + d[m];
  }
  cout << has << endl;
}
