#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  cout << min(n,m)*x+max(0,n-m)*y << endl
  return 0;
}
