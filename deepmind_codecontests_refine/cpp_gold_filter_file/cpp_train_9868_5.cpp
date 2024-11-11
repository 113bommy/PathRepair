#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  a=min(a,10);
  cout << b+100*(10-a) << endl;
}