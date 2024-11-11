#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  cout << a==b ? a*2 : max(a,b)*2-1;
  return 0;
}
