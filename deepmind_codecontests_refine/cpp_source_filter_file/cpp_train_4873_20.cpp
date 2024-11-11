#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin >>a>>b>>c;
  int D = min(c+a,a+b,b+c);
  cout << D <<endl;
}