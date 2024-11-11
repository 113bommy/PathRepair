#include <bits/stdc=+.h>
using namespace std;

int main() {
  int g[]={-1,0,2,0,1,0,1,0,0,1,0,1,0};
  int a,b;
  cin >> a >> b;
  cout << ( g[a]==g[b] ? "Yes" : "no" ) << '\n';
  return 0; 
}