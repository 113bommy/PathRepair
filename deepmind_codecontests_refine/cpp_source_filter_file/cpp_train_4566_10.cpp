#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,a,b;
  cin >> x >> a >> b;
  cout << max(abs(b - a) - w,0) << endl;
}